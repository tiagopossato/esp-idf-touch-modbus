/*
 * SPDX-FileCopyrightText: 2016-2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "string.h"
#include "esp_log.h"
#include "mbcontroller.h"
#include "sdkconfig.h"

#define MB_PORT_NUM (CONFIG_MB_UART_PORT_NUM)   // Number of UART port used for Modbus connection
#define MB_DEV_SPEED (CONFIG_MB_UART_BAUD_RATE) // The communication speed of the UART

// Definições de constantes para a requisição
#define TARGET_SLAVE_ID 0x64                          // Endereço do slave: 0x64
#define FUNCTION_CODE_READ_INPUT_REGS 0x04            // Código de Função: 0x04 (Read Input Registers)
#define START_ADDRESS_TEMP 0x0000                     // Endereço Inicial: 0x0000
#define NUM_REGS_TEMP 0x0002                          // Número de Registradores: 0x0002 (2 registradores)
#define EXPECTED_DATA_BUFFER_SIZE (2 * sizeof(float)) // 8 bytes para dois floats

static void *master_handle = NULL;
static const char *TAG = "MASTER_TEST";

// Note: Some pins on target chip cannot be assigned for UART communication.
// See UART documentation for selected board and target to configure pins using Kconfig.

// The number of parameters that intended to be used in the particular control process
#define MASTER_MAX_CIDS num_device_parameters

// Number of reading of parameters from slave
#define MASTER_MAX_RETRY (1)

// Timeout to update cid over Modbus
#define UPDATE_CIDS_TIMEOUT_MS (2000)
#define UPDATE_CIDS_TIMEOUT_TICS (UPDATE_CIDS_TIMEOUT_MS / portTICK_PERIOD_MS)

// Timeout between polls
#define POLL_TIMEOUT_MS (10)
#define POLL_TIMEOUT_TICS (POLL_TIMEOUT_MS / portTICK_PERIOD_MS)

#define STR(fieldname) ((const char *)(fieldname))
#define TEST_HOLD_REG_START(field) (HOLD_OFFSET(field) >> 1)
#define TEST_HOLD_REG_SIZE(field) (sizeof(((holding_reg_params_t *)0)->field) >> 1)

#define TEST_INPUT_REG_START(field) (INPUT_OFFSET(field) >> 1)
#define TEST_INPUT_REG_SIZE(field) (sizeof(((input_reg_params_t *)0)->field) >> 1)

// Options can be used as bit masks or parameter limits
#define OPTS(min_val, max_val, step_val) {.opt1 = min_val, .opt2 = max_val, .opt3 = step_val}

#define EACH_ITEM(array, length) \
    (typeof(*(array)) *pitem = (array); (pitem < &((array)[length])); pitem++)

// Enumeration of modbus device addresses accessed by master device
enum
{
    MB_DEVICE_ADDR1 = 100 // Only one slave device used for the test (add other slave addresses here)
};

// Enumeration of all supported CIDs for device (used in parameter definition table)
enum
{
    CID_TEMP_DATA_1 = 0,
    CID_HUM_DATA_1,
    CID_COUNT
};

#pragma pack(push, 1)
typedef struct
{
    float input_temp;  // 0
    float input_humid; // 2
} input_params_t;
#pragma pack(pop)

#define INPUT_OFFSET(field) ((uint16_t)(offsetof(input_params_t, field) + 1))
#define INPUT_REG_START(field) (INPUT_OFFSET(field) >> 1)
#define INPUT_REG_SIZE(field) (sizeof(((input_params_t *)0)->field) >> 1)

input_params_t input_params = {0};

// Example Data (Object) Dictionary for Modbus parameters:
// The CID field in the table must be unique.
// Modbus Slave Addr field defines slave address of the device with correspond parameter.
// Modbus Reg Type - Type of Modbus register area (Holding register, Input Register and such).
// Reg Start field defines the start Modbus register number and Reg Size defines the number of registers for the characteristic accordingly.
// The Instance Offset defines offset in the appropriate parameter structure that will be used as instance to save parameter value.
// Data Type, Data Size specify type of the characteristic and its data size.
// Parameter Options field specifies the options that can be used to process parameter value (limits or masks).
// Access Mode - can be used to implement custom options for processing of characteristic (Read/Write restrictions, factory mode values and etc).
const mb_parameter_descriptor_t device_parameters[] = {
    // CID, Name, Units, Modbus addr, register type, Modbus Reg Start Addr, Modbus Reg read length,
    // Instance offset (NA), Instance type, Instance length (bytes), Options (NA), Permissions
    {CID_TEMP_DATA_1, STR("Temp_Sensor_01"), STR("°C"), MB_DEVICE_ADDR1, MB_PARAM_INPUT,
     INPUT_REG_START(input_temp), INPUT_REG_SIZE(input_temp), INPUT_OFFSET(input_temp),
     PARAM_TYPE_FLOAT_CDAB, (INPUT_REG_SIZE(input_temp) << 1), OPTS(-100, 100, 0), PAR_PERMS_READ},

    {CID_HUM_DATA_1, STR("Humid_Sensor_01"), STR("%%rh"), MB_DEVICE_ADDR1, MB_PARAM_INPUT,
     INPUT_REG_START(input_humid), INPUT_REG_SIZE(input_humid), INPUT_OFFSET(input_humid),
     PARAM_TYPE_FLOAT_CDAB, (INPUT_REG_SIZE(input_humid) << 1), OPTS(0, 100, 0), PAR_PERMS_READ}};

// Calculate number of parameters in the table
const uint16_t num_device_parameters = (sizeof(device_parameters) / sizeof(device_parameters[0]));

// The function to get pointer to parameter storage (instance) according to parameter description table
static void *master_get_param_data(const mb_parameter_descriptor_t *param_descriptor)
{
    assert(param_descriptor != NULL);
    void *instance_ptr = NULL;
    if (param_descriptor->param_offset != 0)
    {
        switch (param_descriptor->mb_param_type)
        {
        // case MB_PARAM_HOLDING:
        //     instance_ptr = ((void *)&holding_reg_params + param_descriptor->param_offset - 1);
        //     break;
        case MB_PARAM_INPUT:
            instance_ptr = ((void *)&input_params + param_descriptor->param_offset - 1);
            break;
        // case MB_PARAM_COIL:
        //     instance_ptr = ((void *)&coil_reg_params + param_descriptor->param_offset - 1);
        //     break;
        // case MB_PARAM_DISCRETE:
        //     instance_ptr = ((void *)&discrete_reg_params + param_descriptor->param_offset - 1);
        //     break;
        default:
            instance_ptr = NULL;
            break;
        }
    }
    else
    {
        ESP_LOGE(TAG, "Wrong parameter offset for CID #%u", (unsigned)param_descriptor->cid);
        assert(instance_ptr != NULL);
    }
    return instance_ptr;
}
/**
#define TEST_VERIFY_VALUES(handle, pdescr, pinst) (__extension__(                                  \
    {                                                                                              \
        assert(pinst);                                                                             \
        assert(pdescr);                                                                            \
        uint8_t type = 0;                                                                          \
        esp_err_t err = ESP_FAIL;                                                                  \
        err = mbc_master_get_parameter(handle, pdescr->cid,                                        \
                                       (uint8_t *)pinst, &type);                                   \
        if (err == ESP_OK)                                                                         \
        {                                                                                          \
            bool is_correct = true;                                                                \
            if (pdescr->param_opts.opt3)                                                           \
            {                                                                                      \
            for                                                                                    \
                    EACH_ITEM(pinst, pdescr->param_size / sizeof(*pitem))                          \
                    {                                                                              \
                        if (*pitem != (typeof(*(pinst)))pdescr->param_opts.opt3)                   \
                        {                                                                          \
                            *pitem = (typeof(*(pinst)))pdescr->param_opts.opt3;                    \
                            ESP_LOGD(TAG, "Characteristic #%d (%s), initialize to 0x%" PRIx16 ".", \
                                     (int)pdescr->cid,                                             \
                                     (char *)pdescr->param_key,                                    \
                                     (uint16_t)pdescr->param_opts.opt3);                           \
                            is_correct = false;                                                    \
                        }                                                                          \
                    }                                                                              \
            }                                                                                      \
            if (!is_correct)                                                                       \
            {                                                                                      \
                ESP_LOGE(TAG, "Characteristic #%d (%s), initialize.",                              \
                         (int)pdescr->cid,                                                         \
                         (char *)pdescr->param_key);                                               \
                err = mbc_master_set_parameter(handle, cid, (uint8_t *)pinst, &type);              \
                if (err != ESP_OK)                                                                 \
                {                                                                                  \
                    ESP_LOGE(TAG, "Characteristic #%d (%s) write fail, err = 0x%x (%s).",          \
                             (int)pdescr->cid,                                                     \
                             (char *)pdescr->param_key,                                            \
                             (int)err,                                                             \
                             (char *)esp_err_to_name(err));                                        \
                }                                                                                  \
                else                                                                               \
                {                                                                                  \
                    ESP_LOGI(TAG, "Characteristic #%d %s (%s) value = (..) write successful.",     \
                             (int)pdescr->cid,                                                     \
                             (char *)pdescr->param_key,                                            \
                             (char *)pdescr->param_units);                                         \
                }                                                                                  \
            }                                                                                      \
        }                                                                                          \
        else                                                                                       \
        {                                                                                          \
            ESP_LOGE(TAG, "Characteristic #%d (%s) read fail, err = 0x%x (%s).",                   \
                     (int)pdescr->cid,                                                             \
                     (char *)pdescr->param_key,                                                    \
                     (int)err,                                                                     \
                     (char *)esp_err_to_name(err));                                                \
        }                                                                                          \
        (err);                                                                                     \
    }))
*/

// User operation function to read slave values and check alarm
static void master_operation_func(void *arg)
{
    esp_err_t err = ESP_OK;
    const mb_parameter_descriptor_t *param_descriptor = NULL;

    ESP_LOGI(TAG, "Start modbus test...");

    for (uint16_t retry = 0; retry <= MASTER_MAX_RETRY; retry++)
    {
        // Read all found characteristics from slave(s)
        for (uint16_t cid = 0; (err != ESP_ERR_NOT_FOUND) && cid < MASTER_MAX_CIDS; cid++)
        {
            // Get data from parameters description table
            // and use this information to fill the characteristics description table
            // and having all required fields in just one table
            err = mbc_master_get_cid_info(master_handle, cid, &param_descriptor);
            if ((err != ESP_ERR_NOT_FOUND) && (param_descriptor != NULL))
            {
                void *temp_data_ptr = master_get_param_data(param_descriptor);
                assert(temp_data_ptr);
                uint8_t type = 0;
                err = mbc_master_get_parameter(master_handle, param_descriptor->cid, (uint8_t *)temp_data_ptr, &type);

                if (err == ESP_OK)
                {
                    ESP_LOGI(TAG, "Characteristic #%d %s (%s) value = %f (0x%" PRIx32 ") read successful.",
                             (int)param_descriptor->cid,
                             (char *)param_descriptor->param_key,
                             (char *)param_descriptor->param_units,
                             *(float *)temp_data_ptr,
                             *(uint32_t *)temp_data_ptr);
                }
                else
                {
                    ESP_LOGE(TAG, "Characteristic #%d (%s) read fail, err = 0x%x (%s).",
                             (int)param_descriptor->cid,
                             (char *)param_descriptor->param_key,
                             (int)err,
                             (char *)esp_err_to_name(err));
                }
                vTaskDelay(POLL_TIMEOUT_TICS); // timeout between polls
            }
        }
        vTaskDelay(UPDATE_CIDS_TIMEOUT_TICS);
    }

    ESP_LOGI(TAG, "Destroy master...");
    ESP_ERROR_CHECK(mbc_master_delete(master_handle));
}

// Modbus master initialization
static esp_err_t master_init(void)
{
    // Initialize Modbus controller
    mb_communication_info_t comm = {
        .ser_opts.port = MB_PORT_NUM,
#if CONFIG_MB_COMM_MODE_ASCII
        .ser_opts.mode = MB_ASCII,
#elif CONFIG_MB_COMM_MODE_RTU
        .ser_opts.mode = MB_RTU,
#endif
        .ser_opts.baudrate = MB_DEV_SPEED,
        .ser_opts.parity = MB_PARITY_NONE,
        .ser_opts.uid = 0,
        .ser_opts.response_tout_ms = 1000,
        .ser_opts.data_bits = UART_DATA_8_BITS,
        .ser_opts.stop_bits = UART_STOP_BITS_1};

    esp_err_t err = mbc_master_create_serial(&comm, &master_handle);
    MB_RETURN_ON_FALSE((master_handle != NULL), ESP_ERR_INVALID_STATE, TAG,
                       "mb controller initialization fail.");
    MB_RETURN_ON_FALSE((err == ESP_OK), ESP_ERR_INVALID_STATE, TAG,
                       "mb controller initialization fail, returns(0x%x).", (int)err);

    // Set UART pin numbers
    err = uart_set_pin(MB_PORT_NUM, CONFIG_MB_UART_TXD, CONFIG_MB_UART_RXD,
                       UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    MB_RETURN_ON_FALSE((err == ESP_OK), ESP_ERR_INVALID_STATE, TAG,
                       "mb serial set pin failure, uart_set_pin() returned (0x%x).", (int)err);

    err = mbc_master_start(master_handle);
    MB_RETURN_ON_FALSE((err == ESP_OK), ESP_ERR_INVALID_STATE, TAG,
                       "mb controller start fail, returned (0x%x).", (int)err);

    // Set driver mode to Half Duplex
    err = uart_set_mode(MB_PORT_NUM, UART_MODE_RS485_HALF_DUPLEX);
    MB_RETURN_ON_FALSE((err == ESP_OK), ESP_ERR_INVALID_STATE, TAG,
                       "mb serial set mode failure, uart_set_mode() returned (0x%x).", (int)err);

    vTaskDelay(5);
    err = mbc_master_set_descriptor(master_handle, &device_parameters[0], num_device_parameters);
    MB_RETURN_ON_FALSE((err == ESP_OK), ESP_ERR_INVALID_STATE, TAG,
                       "mb controller set descriptor fail, returns(0x%x).", (int)err);
    ESP_LOGI(TAG, "Modbus master stack initialized...");
    return err;
}

void app_main(void)
{
    // Initialization of device peripheral and objects
    ESP_ERROR_CHECK(master_init());
    vTaskDelay(10);

    master_operation_func(NULL);
    /**
        esp_err_t err = ESP_OK;
        mb_param_request_t req = {0}; // Inicializa a estrutura da requisição com zeros
                                // Configura os parâmetros da requisição Modbus
        // Correspondendo aos bytes 0x64 0x4 0x0 0x0 0x0 0x2
        req.slave_addr = TARGET_SLAVE_ID;            // 0x64 (endereço do slave)
        req.command = FUNCTION_CODE_READ_INPUT_REGS; // 0x04 (código da função)
        req.reg_start = START_ADDRESS_TEMP;          // 0x0000 (endereço inicial do registrador)
        req.reg_size = NUM_REGS_TEMP;                // 0x0002 (quantidade de registradores)

        // Buffer para armazenar os dados recebidos do slave
        // Este buffer receberá apenas a parte de "dados" da resposta,
        // sem o cabeçalho Modbus ou o CRC.
        uint8_t received_data_buffer[EXPECTED_DATA_BUFFER_SIZE];
        memset(received_data_buffer, 0, EXPECTED_DATA_BUFFER_SIZE); // Limpa o buffer antes de usar

        ESP_LOGI("MODBUS_REQUEST", "Enviando requisição para Slave ID: 0x%02X, FC: 0x%02X, Start Reg: 0x%04X, Num Regs: 0x%04X",
                 req.slave_addr, req.command, req.reg_start, req.reg_size);

        // Envia a requisição Modbus
        // A função mbc_master_send_request irá montar o frame Modbus RTU completo (incluindo CRC)
        // e enviá-lo pelo UART. Ela também aguardará e processará a resposta.
        err = mbc_master_send_request(master_handle, &req, (void *)&received_data_buffer[0]);

        if (err != ESP_OK)
        {
            ESP_LOGE("MODBUS_REQUEST", "Falha ao enviar/receber requisição: %s", esp_err_to_name(err));
        }
        else
        {
            ESP_LOGI("MODBUS_REQUEST", "Requisição enviada com sucesso.");
            ESP_LOGI("MODBUS_RESPONSE_DATA", "Dados recebidos (%zu bytes):", EXPECTED_DATA_BUFFER_SIZE);
            // Imprime o conteúdo do buffer de dados recebido em formato hexadecimal
            ESP_LOG_BUFFER_HEX_LEVEL("MODBUS_RESPONSE_DATA", received_data_buffer, EXPECTED_DATA_BUFFER_SIZE, ESP_LOG_INFO);
        }
            */
}
