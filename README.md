# esp-idf-touch-modbus

Configuração de pino RTS removida para evitar conflitos. Usando UART_PIN_NO_CHANGE

# Log no monitor serial

```
000 - 0xESP-ROM:esp32s3-20210327
Build:Mar 27 2021
rst:0x15 (USB_UART_CHIP_RESET),boot:0x8 (SPI_FAST_FLASH_BOOT)
Saved PC:0x40048839
--- 0x40048839: uart_tx_one_char_uart in ROM
SPIWP:0xee
mode:DIO, clock div:1
load:0x3fce2820,len:0x110c
load:0x403c8700,len:0xb30
load:0x403cb700,len:0x2d64
entry 0x403c88a4
V (95) mmap: after coalescing, 1 regions are left
I (95) octal_psram: vendor id    : 0x0d (AP)
I (95) octal_psram: dev id       : 0x02 (generation 3)
I (97) octal_psram: density      : 0x03 (64 Mbit)
I (101) octal_psram: good-die     : 0x01 (Pass)
I (106) octal_psram: Latency      : 0x01 (Fixed)
I (110) octal_psram: VCC          : 0x01 (3V)
I (114) octal_psram: SRF          : 0x01 (Fast Refresh)
I (119) octal_psram: BurstType    : 0x01 (Hybrid Wrap)
I (124) octal_psram: BurstLen     : 0x01 (32 Byte)
I (128) octal_psram: Readlatency  : 0x02 (10 cycles@Fixed)
I (134) octal_psram: DriveStrength: 0x00 (1/1)
V (138) MSPI Timing: config_idx: 0, good
V (141) MSPI Timing: config_idx: 1, good
V (145) MSPI Timing: config_idx: 2, bad
V (149) MSPI Timing: config_idx: 3, good
V (152) MSPI Timing: config_idx: 4, good
V (156) MSPI Timing: config_idx: 5, good
V (160) MSPI Timing: config_idx: 6, good
V (163) MSPI Timing: config_idx: 7, good
V (167) MSPI Timing: config_idx: 8, bad
V (170) MSPI Timing: config_idx: 9, good
V (174) MSPI Timing: config_idx: 10, good
V (178) MSPI Timing: config_idx: 11, good
V (182) MSPI Timing: config_idx: 12, good
V (185) MSPI Timing: config_idx: 13, good
D (189) MSPI Timing: test nums: 1, test result: [id][good/bad][good_times]:
D (196) MSPI Timing: [0][good][1] 
D (199) MSPI Timing: [1][good][1] 
D (202) MSPI Timing: [2][bad][0] 
D (205) MSPI Timing: [3][good][1] 
D (208) MSPI Timing: [4][good][1] 
D (211) MSPI Timing: [5][good][1] 
D (214) MSPI Timing: [6][good][1] 
D (217) MSPI Timing: [7][good][1] 
D (221) MSPI Timing: [8][bad][0] 
D (224) MSPI Timing: [9][good][1] 
D (227) MSPI Timing: [10][good][1] 
D (230) MSPI Timing: [11][good][1] 
D (233) MSPI Timing: [12][good][1] 
D (236) MSPI Timing: [13][good][1] 
D (240) MSPI Timing: tuning success, best point is index 5
I (245) MSPI Timing: PSRAM timing tuning index: 5
I (249) esp_psram: Found 8MB PSRAM device
I (253) esp_psram: Speed: 80MHz
V mmu_psram: Rodata from flash page1 copy to SPIRAM page0, Offset: 1
V (275) mmu_psram: after copy rodata, page_id is 2
I (275) mmu_psram: Read only data copied and mapped to SPIRAM
V (275) esp_psram: after copy .rodata, used page is 2, start_page is 2, available_size is 8257536 B
V mmu_psram: Instructions from flash page3 copy to SPIRAM page2, Offset: 1
V (309) mmu_psram: after copy instruction, page_id is 5
I (310) mmu_psram: Instructions copied and mapped to SPIRAM
V (310) esp_psram: after copy .text, used page is 3, start_page is 5, psram_available_size is 1070510752 B
V (318) mmap: found laddr is 0x50000
V (321) esp_psram: 8bit-aligned-region: actual_mapped_len is 0x7b0000 bytes
V (328) esp_psram: 8bit-aligned-range: 0x7b0000 B, starting from: 0x3c050000
I (335) cpu_start: Multicore app
D (337) cpu_start: Pro cpu up
D (340) cpu_start: Starting app cpu, entry point is 0x40375630
--- 0x40375630: call_start_cpu1 at /home/tiago/esp/v5.5/esp-idf/components/esp_system/port/cpu_start.c:196
D (0) cpu_start: App cpu up
V CACHE_ERR: illegal error intr clr & ena mask is: 0x3f
V CACHE_ERR: core 1 access error intr clr & ena mask is: 0x1f
I (761) esp_psram: SPI SRAM memory test OK
D (770) clk: RTC_SLOW_CLK calibration value: 3434330
V CACHE_ERR: illegal error intr clr & ena mask is: 0x3f
V CACHE_ERR: core 0 access error intr clr & ena mask is: 0x1f
D (775) cpu_start: calling init function: 0x42001e6c on core: 0
--- 0x42001e6c: __esp_system_init_fn_init_efuse_check at /home/tiago/esp/v5.5/esp-idf/components/efuse/src/esp_efuse_startup.c:37
D (779) cpu_start: calling init function: 0x42001fb0 on core: 0
--- 0x42001fb0: __esp_system_init_fn_init_show_cpu_freq at /home/tiago/esp/v5.5/esp-idf/components/esp_system/startup_funcs.c:64
I (785) cpu_start: Pro cpu start user code
I (789) cpu_start: cpu freq: 240000000 Hz
D (792) cpu_start: calling init function: 0x42001d9c on core: 0
--- 0x42001d9c: __esp_system_init_fn_init_show_app_info at /home/tiago/esp/v5.5/esp-idf/components/esp_app_format/esp_app_desc.c:123
I (798) app_init: Application information:
I (802) app_init: Project name:     new_modbus_test
I (806) app_init: App version:      d545239-dirty
I (811) app_init: Compile time:     Jul 28 2025 16:08:00
I (816) app_init: ELF file SHA256:  13e39d577...
I (820) app_init: ESP-IDF:          v5.5-dirty
D (824) cpu_start: calling init function: 0x42001e80 on core: 0
--- 0x42001e80: __esp_system_init_fn_init_efuse_show_app_info at /home/tiago/esp/v5.5/esp-idf/components/efuse/src/esp_efuse_startup.c:47
I (830) efuse_init: Min chip rev:     v0.0
I (834) efuse_init: Max chip rev:     v0.99 
I (838) efuse_init: Chip rev:         v0.2
D (842) cpu_start: calling init function: 0x42003c2c on core: 0
--- 0x42003c2c: __esp_system_init_fn_init_heap at /home/tiago/esp/v5.5/esp-idf/components/heap/heap_caps_init.c:26
V (847) memory_layout: reserved range is 0x3c0406d0 - 0x3c040700
D (853) memory_layout: Checking 7 reserved memory ranges:
D (858) memory_layout: Reserved memory range 0x3c000000 - 0x3e000000
D (864) memory_layout: Reserved memory range 0x3fc84000 - 0x3fc96c00
D (870) memory_layout: Reserved memory range 0x3fc96c00 - 0x3fc9a9d0
D (876) memory_layout: Reserved memory range 0x3fceee34 - 0x3fcf0000
D (882) memory_layout: Reserved memory range 0x40374000 - 0x40386c00
--- 0x40374000: _WindowOverflow4 at /home/tiago/esp/v5.5/esp-idf/components/xtensa/xtensa_vectors.S:2027
D (889) memory_layout: Reserved memory range 0x600fe000 - 0x600fe020
D (895) memory_layout: Reserved memory range 0x600fffe8 - 0x60100000
D (901) memory_layout: Building list of available memory regions:
V (906) memory_layout: Examining memory region 0x3fc88000 - 0x3fc90000
V (913) memory_layout: Region 0x3fc88000 - 0x3fc90000 inside of reserved 0x3fc84000 - 0x3fc96c00
V (921) memory_layout: Examining memory region 0x3fc90000 - 0x3fca0000
V (927) memory_layout: Start of region 0x3fc90000 - 0x3fca0000 overlaps reserved 0x3fc84000 - 0x3fc96c00
V (937) memory_layout: Start of region 0x3fc96c00 - 0x3fca0000 overlaps reserved 0x3fc96c00 - 0x3fc9a9d0
D (946) memory_layout: Available memory region 0x3fc9a9d0 - 0x3fca0000
V (952) memory_layout: Examining memory region 0x3fca0000 - 0x3fcb0000
D (958) memory_layout: Available memory region 0x3fca0000 - 0x3fcb0000
V (965) memory_layout: Examining memory region 0x3fcb0000 - 0x3fcc0000
D (971) memory_layout: Available memory region 0x3fcb0000 - 0x3fcc0000
V (977) memory_layout: Examining memory region 0x3fcc0000 - 0x3fcd0000
D (983) memory_layout: Available memory region 0x3fcc0000 - 0x3fcd0000
V (990) memory_layout: Examining memory region 0x3fcd0000 - 0x3fce0000
D (996) memory_layout: Available memory region 0x3fcd0000 - 0x3fce0000
V (1002) memory_layout: Examining memory region 0x3fce0000 - 0x3fce9710
D (1008) memory_layout: Available memory region 0x3fce0000 - 0x3fce9710
V (1015) memory_layout: Examining memory region 0x3fce9710 - 0x3fcf0000
V (1021) memory_layout: End of region 0x3fce9710 - 0x3fcf0000 overlaps reserved 0x3fceee34 - 0x3fcf0000
D (1030) memory_layout: Available memory region 0x3fce9710 - 0x3fceee34
V (1037) memory_layout: Examining memory region 0x3fcf0000 - 0x3fcf8000
D (1043) memory_layout: Available memory region 0x3fcf0000 - 0x3fcf8000
V (1049) memory_layout: Examining memory region 0x3c000000 - 0x3e000000
V (1056) memory_layout: Region 0x3c000000 - 0x3e000000 inside of reserved 0x3c000000 - 0x3e000000
V (1064) memory_layout: Examining memory region 0x600fe000 - 0x60100000
V (1071) memory_layout: Start of region 0x600fe000 - 0x60100000 overlaps reserved 0x600fe000 - 0x600fe020
V (1080) memory_layout: End of region 0x600fe020 - 0x60100000 overlaps reserved 0x600fffe8 - 0x60100000
D (1089) memory_layout: Available memory region 0x600fe020 - 0x600fffe8
I (1095) heap_init: Initializing. RAM available for dynamic allocation:
D (1102) heap_init: New heap initialised at 0x3fc9a9d0
I (1106) heap_init: At 3FC9A9D0 len 0004ED40 (315 KiB): RAM
I (1112) heap_init: At 3FCE9710 len 00005724 (21 KiB): RAM
D (1117) heap_init: New heap initialised at 0x3fcf0000
I (1122) heap_init: At 3FCF0000 len 00008000 (32 KiB): DRAM
D (1127) heap_init: New heap initialised at 0x600fe020
I (1132) heap_init: At 600FE020 len 00001FC8 (7 KiB): RTCRAM
D (1137) cpu_start: calling init function: 0x420071dc on core: 0
--- 0x420071dc: __esp_system_init_fn_esp_timer_init_nonos at /home/tiago/esp/v5.5/esp-idf/components/esp_timer/src/esp_timer_init.c:28
D (1143) cpu_start: calling init function: 0x42006db4 on core: 0
--- 0x42006db4: __esp_system_init_fn_init_libc at /home/tiago/esp/v5.5/esp-idf/components/newlib/src/init.c:12
D (1149) cpu_start: calling init function: 0x42009f30 on core: 0
--- 0x42009f30: __esp_system_init_fn_add_psram_to_heap at /home/tiago/esp/v5.5/esp-idf/components/esp_psram/system_layer/esp_psram.c:115
I (1155) esp_psram: Adding pool of 7872K of PSRAM memory to heap allocator
I (1161) esp_psram: Adding pool of 62K of PSRAM memory gap generated due to end address alignment of drom to the heap allocator
D (1172) cpu_start: calling init function: 0x42001ffc on core: 0
--- 0x42001ffc: __esp_system_init_fn_init_brownout at /home/tiago/esp/v5.5/esp-idf/components/esp_system/startup_funcs.c:79
V (1178) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): checking args
V (1184) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): Args okay. Resulting flags 0x40E
D (1192) intr_alloc: Connected src 39 to int 1 (cpu 0)
D (1197) cpu_start: calling init function: 0x4200200c on core: 0
--- 0x4200200c: __esp_system_init_fn_init_newlib_time at /home/tiago/esp/v5.5/esp-idf/components/esp_system/startup_funcs.c:104
D (1203) cpu_start: calling init function: 0x42021ee0 on core: 0
--- 0x42021ee0: __esp_system_init_fn_init_vfs_uart at /home/tiago/esp/v5.5/esp-idf/components/esp_driver_uart/src/uart_vfs.c:1148
D (1208) cpu_start: calling init function: 0x420224a8 on core: 0
--- 0x420224a8: __esp_system_init_fn_init_vfs_usj_sec at /home/tiago/esp/v5.5/esp-idf/components/esp_driver_usb_serial_jtag/src/usb_serial_jtag_vfs.c:628
D (1214) cpu_start: calling init function: 0x42009970 on core: 0
--- 0x42009970: __esp_system_init_fn_init_vfs_nullfs at /home/tiago/esp/v5.5/esp-idf/components/vfs/nullfs.c:322
D (1220) cpu_start: calling init function: 0x4200968c on core: 0
--- 0x4200968c: __esp_system_init_fn_init_vfs_console at /home/tiago/esp/v5.5/esp-idf/components/esp_vfs_console/vfs_console.c:271
D (1226) cpu_start: calling init function: 0x42006dc0 on core: 0
--- 0x42006dc0: __esp_system_init_fn_init_libc_stdio at /home/tiago/esp/v5.5/esp-idf/components/newlib/src/init.c:18
D (1231) cpu_start: calling init function: 0x42002018 on core: 0
--- 0x42002018: __esp_system_init_fn_init_flash at /home/tiago/esp/v5.5/esp-idf/components/esp_system/startup_funcs.c:111
V (1237) memspi: raw_chip_id: 184046

V (1240) memspi: chip_id: 464018

V (1244) memspi: raw_chip_id: 184046

V (1247) memspi: chip_id: 464018

D (1250) spi_flash: trying chip: issi
D (1254) spi_flash: trying chip: gd
D (1257) spi_flash: trying chip: mxic
D (1260) spi_flash: trying chip: winbond
D (1264) spi_flash: trying chip: boya
D (1267) spi_flash: trying chip: th
D (1270) spi_flash: trying chip: mxic (opi)
D (1274) spi_flash: trying chip: generic
I (1278) spi_flash: detected chip: generic
I (1282) spi_flash: flash io: dio
D (1285) cpu_start: calling init function: 0x42001f1c on core: 0
--- 0x42001f1c: __esp_system_init_fn_init_efuse at /home/tiago/esp/v5.5/esp-idf/components/efuse/src/esp_efuse_startup.c:158
D (1291) cpu_start: calling init function: 0x42013690
--- 0x42013690: _GLOBAL__sub_I__ZN17__eh_globals_init7_S_initE at /builds/idf/crosstool-NG/.build/xtensa-esp-elf/src/gcc/libstdc++-v3/libsupc++/eh_globals.cc:162
D (1296) cpu_start: calling init function: 0x4037b2b8
--- 0x4037b2b8: enable_timer_group0_for_calibration at /home/tiago/esp/v5.5/esp-idf/components/esp_hw_support/port/esp32s3/rtc_time.c:201
D (1300) cpu_start: calling init function: 0x42003340
--- 0x42003340: esp_ipc_init at /home/tiago/esp/v5.5/esp-idf/components/esp_system/esp_ipc.c:107
D (1305) cpu_start: calling init function: 0x420131d0 on core: 0
--- 0x420131d0: __esp_system_init_fn_esp_timer_init_os at /home/tiago/esp/v5.5/esp-idf/components/esp_timer/src/esp_timer.c:566
V (1311) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): checking args
V (1317) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): Args okay. Resulting flags 0xC02
D (1325) intr_alloc: Connected src 59 to int 2 (cpu 0)
D (1329) cpu_start: calling init function: 0x42020b70 on core: 0
--- 0x42020b70: __esp_system_init_fn_esp_security_init at /home/tiago/esp/v5.5/esp-idf/components/esp_security/src/init.c:38
D (1335) cpu_start: calling init function: 0x42004cfc on core: 0
--- 0x42004cfc: __esp_system_init_fn_esp_sleep_startup_init at /home/tiago/esp/v5.5/esp-idf/components/esp_hw_support/sleep_gpio.c:225
I (1341) sleep_gpio: Configure to isolate all GPIO pins in sleep state
I (1347) sleep_gpio: Enable automatic switching of GPIO sleep configuration
D (1354) cpu_start: calling init function: 0x4200204c on core: 0
--- 0x4200204c: __esp_system_init_fn_init_apb_dma at /home/tiago/esp/v5.5/esp-idf/components/esp_system/startup_funcs.c:150
D (1360) cpu_start: calling init function: 0x4200941c on core: 0
--- 0x4200941c: __esp_system_init_fn_usb_serial_jtag_conn_status_init at /home/tiago/esp/v5.5/esp-idf/components/esp_driver_usb_serial_jtag/src/usb_serial_jtag_connection_monitor.c:75
D (1365) cpu_start: calling init function: 0x42002058 on core: 0
--- 0x42002058: __esp_system_init_fn_init_disable_rtc_wdt at /home/tiago/esp/v5.5/esp-idf/components/esp_system/startup_funcs.c:168
V (1371) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): checking args
V (1377) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): Args okay. Resulting flags 0x40E
D (1385) intr_alloc: Connected src 79 to int 3 (cpu 0)
D (1390) app_start: Starting scheduler on CPU0
V (1394) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): checking args
V (1394) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): Args okay. Resulting flags 0x402
D (1394) intr_alloc: Connected src 57 to int 5 (cpu 0)
V (1394) intr_alloc: esp_intr_alloc_intrstatus (cpu 1): checking args
V (1404) intr_alloc: esp_intr_alloc_intrstatus (cpu 1): Args okay. Resulting flags 0x40E
D (1404) intr_alloc: Connected src 80 to int 0 (cpu 1)
D (1414) app_start: Starting scheduler on CPU1
V (1414) intr_alloc: esp_intr_alloc_intrstatus (cpu 1): checking args
V (1424) intr_alloc: esp_intr_alloc_intrstatus (cpu 1): Args okay. Resulting flags 0x402
D (1434) intr_alloc: Connected src 58 to int 1 (cpu 1)
I (1394) main_task: Started on CPU0
D (1444) heap_init: New heap initialised at 0x3fce9710
I (1444) esp_psram: Reserving pool of 32K of internal memory for DMA/internal allocations
D (1454) esp_psram: Allocating block of size 32768 bytes
V (1454) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): checking args
V (1464) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): Args okay. Resulting flags 0xE
D (1474) intr_alloc: Connected src 52 to int 8 (cpu 0)
I (1474) main_task: Calling app_main()
I (1484) uart: queue free spaces: 20
V (1484) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): checking args
V (1484) intr_alloc: esp_intr_alloc_intrstatus (cpu 0): Args okay. Resulting flags 0x40E
D (1494) intr_alloc: Connected src 29 to int 9 (cpu 0)
I (1504) mb_port.serial: mbm_rtu@0x3fce9a78, suspend port from task.
D (1504) mb_port.serial: created object @0x3fceb0f4
D (1514) mb_port.timer: initialized mb_port.timer object @0x3fceccb4
D (1514) mb_port.event: initialized object @0x3fceccec
D (1524) mb_transp.rtu_master: created mb_transp.rtu_master object @0x3fceae38
D (1534) MB_FUNC_HANDLING: Inst: 0x3fce9a78, add handler: 0x11, 0x4200e638
--- 0x4200e638: mbm_fn_report_slave_id at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfuncother.c:100
D (1534) MB_FUNC_HANDLING: Inst: 0x3fce9a78, add handler: 0x4, 0x4200e484
--- 0x4200e484: mbm_fn_read_inp_reg at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfuncinput_master.c:91
D (1544) MB_FUNC_HANDLING: Inst: 0x3fce9a78, add handler: 0x3, 0x4200e198
--- 0x4200e198: mbm_fn_read_holding_reg at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfuncholding_master.c:297
D (1554) MB_FUNC_HANDLING: Inst: 0x3fce9a78, add handler: 0x10, 0x4200e07c
--- 0x4200e07c: mbm_fn_write_multi_holding_reg at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfuncholding_master.c:206
D (1554) MB_FUNC_HANDLING: Inst: 0x3fce9a78, add handler: 0x6, 0x4200df40
--- 0x4200df40: mbm_fn_write_holding_reg at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfuncholding_master.c:119
D (1564) MB_FUNC_HANDLING: Inst: 0x3fce9a78, add handler: 0x17, 0x4200e330
--- 0x4200e330: mbm_fn_rw_multi_holding_regs at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfuncholding_master.c:416
D (1574) MB_FUNC_HANDLING: Inst: 0x3fce9a78, add handler: 0x1, 0x4200daa4
--- 0x4200daa4: mbm_fn_read_coils at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfunccoils_master.c:106
D (1574) MB_FUNC_HANDLING: Inst: 0x3fce9a78, add handler: 0x5, 0x42020c40
--- 0x42020c40: mbm_fn_write_coil at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfunccoils_master.c:207
D (1584) MB_FUNC_HANDLING: Inst: 0x3fce9a78, add handler: 0xf, 0x4200dcd4
--- 0x4200dcd4: mbm_fn_write_multi_coils at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfunccoils_master.c:286
D (1584) MB_FUNC_HANDLING: Inst: 0x3fce9a78, add handler: 0x2, 0x4200de10
--- 0x4200de10: mbm_fn_read_discrete_inputs at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfuncdisc_master.c:88
D (1594) mb_object.master: created object mbm_rtu@0x3fce9a78
D (1604) mb_port.serial: mbm_rtu@0x3fce9a78, resume port.
D (1614) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (1614) mb_port.timer: timer mode: (0) triggered
D (1604) mb_port.timer: mbm_rtu@0x3fce9a78, start timer (4000).
D (1624) mb_object.master: 0x3fce9a78:EV_READY
D (1644) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (1644) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 35.
D (1644) mb_port.serial: mbm_rtu@0x3fce9a78, frame 35 bytes is ready.
D (1644) mb_object.master: 0x3fce9a78:EV_FRAME_RECEIVED
V (1654) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (1654) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (1664) mb_port.serial: mbm_rtu@0x3fce9a78, received data: 35 bytes.
D (1674) mbm_rtu@0x3fce9a78:PORT_RECV: 20 e6 74 38 2a 10 bd 29 c5 fd 31 ac ec 20 a6 19
D (1674) mbm_rtu@0x3fce9a78:PORT_RECV: 63 96 86 94 63 96 c4 d0 19 c6 10 31 01 a6 4b c6
D (1684) mbm_rtu@0x3fce9a78:PORT_RECV: 08 11 fc
D (1694) mb_port.serial: mbm_rtu@0x3fce9a78, serial processing time[us] = 539693
D (1694) mb_object.master: 0x3fce9a78, packet data receive failed (addr=0)(5).
D (1704) mb_object.master: 0x3fce9a78:EV_ERROR_PROCESS
D (1704) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (1714) mb_object.master: 0x3fce9a78, transaction processing time(us) = 0
D (1724) mb_port.event: mbm_rtu@0x3fce9a78, mb resource release.
I (1724) MASTER_TEST: Modbus master stack initialized...
D (1744) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (1744) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 98.
D (1744) mb_port.serial: mbm_rtu@0x3fce9a78, frame 98 bytes is ready.
D (1754) mb_object.master: 0x3fce9a78:EV_FRAME_RECEIVED
V (1754) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (1764) mb_port.timer: mbm_rtu@0x3fce9a78, timerD (1764) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (1774) mb_port.serial: mbm_rtu@0x3fce9a78, uart rx break.
 stop, returns 259.
D (1784) mb_port.serial: mbm_rtu@0x3fce9a78, received data: 98 bytes.
D (1784) mbm_rtu@0x3fce9a78:PORT_RECV: 94 43 b9 21 21 5a 95 fb 14 bd 1c 88 18 ec 20 93
D (1794) mbm_rtu@0x3fce9a78:PORT_RECV: 29 20 14 29 c6 10 c6 90 87 c5 62 88 10 63 96 c5
D (1804) mbm_rtu@0x3fce9a78:PORT_RECV: d1 19 c6 31 c4 ee 84 31 2d 1c 50 ad 94 ae 94 ee
D (1814) mbm_rtu@0x3fce9a78:PORT_RECV: 21 d9 b5 8c 8c 92 ee 21 98 96 4c c6 53 c4 df 10
D (1814) mbm_rtu@0x3fce9a78:PORT_RECV: a4 4e 4e 9c 08 31 8e 10 dc 29 c6 1f f5 ac 29 cc
D (1824) mbm_rtu@0x3fce9a78:PORT_RECV: b7 03 c7 08 31 cc 31 12 f6 c5 29 f9 21 9a 00 de
D (1834) mbm_rtu@0x3fce9a78:PORT_RECV: 1d 2c
D (1834) mb_port.serial: mbm_rtu@0x3fce9a78, serial processing time[us] = 656384
D (1844) mb_object.master: 0x3fce9a78, packet data receive failed (addr=0)(5).
D (1854) mb_object.master: 0x3fce9a78:EV_ERROR_PROCESS
D (1854) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (1864) mb_object.master: 0x3fce9a78, transaction processing time(us) = 0
D (1864) mb_port.event: mbm_rtu@0x3fce9a78, mb resource release.
D (1874) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (1884) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 119.
I (1884) MASTER_TEST: Start modbus test...
D (1894) mb_port.event: mbm_rtu@0x3fce9a78, mb take resource, (300 ticks).
D (1894) mbm_rtu@0x3fce9a78:MB_TRANSMIT: 04 00 00 00 02
V (1904) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (1904) mb_port.event: mbm_rtu@0x3fce9a78, mb_port_event_wait_req_finish: returned event = 0x100
D (1914) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (1924) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 1.
D (1924) mb_port.serial: mbm_rtu@0x3fce9a78, tx buffer sent: (8) bytes.
D (1934) mbm_rtu@0x3fce9a78:PORT_SEND: 64 04 00 00 00 02 78 3e
D (1934) mb_port.timer: mbm_rtu@0x3fce9a78, respond enable timeout (1000).
D (1944) mb_object.master: 0x3fce9a78:EV_FRAME_SENT
D (1954) mbc_serial.master: mbc_serial_master_get_parameter: Bad response to get cid(0) = ESP_ERR_INVALID_RESPONSE
E (1964) MB_CONTROLLER_MASTER: mbc_master_get_parameter(131): Master get parameter failure, error=(0x108) (ESP_ERR_INVALID_RESPONSE).
E (1974) MASTER_TEST: Characteristic #0 (Temp_Sensor_01) read fail, err = 0x108 (ESP_ERR_INVALID_RESPONSE).
D (1994) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (1994) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 64.
D (1994) mb_port.serial: mbm_rtu@0x3fce9a78, frame 64 bytes is ready.
D (2004) mb_object.master: 0x3fce9a78:EV_FRAME_RECEIVED
V (2004) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (2014) mb_port.serial: mbm_rtu@0x3fce9a78, received data: 64 bytes.
D (2024) mbm_rtu@0x3fce9a78:PORT_RECV: d7 8c a5 90 00 5e 31 1d 20 94 31 93 f6 31 29 ab
D (2024) mbm_rtu@0x3fce9a78:PORT_RECV: 86 94 ee 21 d9 84 0c ed c6 52 21 c4 10 cd 9c ff
D (2034) mbm_rtu@0x3fce9a78:PORT_RECV: 04 5d 1e 9c a4 86 21 7d 10 10 39 d5 ac 18 01 1d
D (2044) mbm_rtu@0x3fce9a78:PORT_RECV: 10 21 df 86 06 08 34 01 98 a8 43 08 21 21 10 fe
D (2054) mb_port.serial: mbm_rtu@0x3fce9a78, serial processing time[us] = 74576
D (2054) mb_object.master: 0x3fce9a78, packet data receive failed (addr=0)(5).
D (2064) mb_object.master: 0x3fce9a78:EV_ERROR_PROCESS
D (2064) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (2074) mbm_error_cb_receive_data: 04 00 00 00 02
D (2084) mb_object.master: 0x3fce9a78, transaction processing time(us) = 168291
D (2084) mb_port.event: mbm_rtu@0x3fce9a78, mb take resource, (300 ticks).
D (2094) mbm_rtu@0x3fce9a78:MB_TRANSMIT: 04 00 02 00 02
V (2094) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (2104) mb_port.event: mbm_rtu@0x3fce9a78, mb_port_event_wait_req_finish: returned event = 0x100
D (2104) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (2114) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 1.
D (2124) mb_port.serial: mbm_rtu@0x3fce9a78, tx buffer sent: (8) bytes.
D (2134) mbm_rtu@0x3fce9a78:PORT_SEND: 64 04 00 02 00 02 d9 fe
D (2134) mb_port.timer: mbm_rtu@0x3fce9a78, respond enable timeout (1000).
D (2144) mb_object.master: 0x3fce9a78:EV_FRAME_SENT
D (2144) mbc_serial.master: mbc_serial_master_get_parameter: Bad response to get cid(1) = ESP_ERR_INVALID_RESPONSE
E (2154) MB_CONTROLLER_MASTER: mbc_master_get_parameter(131): Master get parameter failure, error=(0x108) (ESP_ERR_INVALID_RESPONSE).
D (2154) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (2174) mb_port.serial: mbm_rtu@0x3fce9a78, uart rx break.
E (2184) MASTER_TEST: Characteristic #1 (Humid_Sensor_01) read fail, err = 0x108 (ESP_ERR_INVALID_RESPONSE).
D (2204) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (2204) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 74.
D (2204) mb_port.serial: mbm_rtu@0x3fce9a78, frame 74 bytes is ready.
D (2214) mb_object.master: 0x3fce9a78:EV_FRAME_RECEIVED
V (2214) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (2224) mb_port.serial: mbm_rtu@0x3fce9a78, received data: 74 bytes.
D (2224) mbm_rtu@0x3fce9a78:PORT_RECV: 8d 49 8f 10 ed 4a cd 1d 21 95 30 93 f6 8c 29 d6
D (2234) mbm_rtu@0x3fce9a78:PORT_RECV: 18 21 18 21 10 84 86 14 ea 29 ad 31 9d da 21 8d
D (2244) mbm_rtu@0x3fce9a78:PORT_RECV: 00 10 1f 31 a4 14 a1 12 26 84 06 d5 ac 72 00 29
D (2254) mbm_rtu@0x3fce9a78:PORT_RECV: 29 1f a6 c5 06 08 3c 43 b0 21 20 72 30 ec 21 21
D (2254) mbm_rtu@0x3fce9a78:PORT_RECV: 0c 08 15 a8 38 31 21 5f 08 fc
D (2264) mb_port.serial: mbm_rtu@0x3fce9a78, serial processing time[us] = 85244
D (2274) mb_object.master: 0x3fce9a78, packet data receive failed (addr=0)(5).
D (2274) mb_object.master: 0x3fce9a78:EV_ERROR_PROCESS
D (2284) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (2284) mbm_error_cb_receive_data: 04 00 02 00 02
D (2294) mb_object.master: 0x3fce9a78, transaction processing time(us) = 185068
D (2314) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (2314) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 103.
D (2314) mb_port.serial: mbm_rtu@0x3fce9a78, frame 103 bytes is ready.
D (2324) mb_object.master: 0x3fce9a78:EV_FRAME_RECEIVED
V (2324) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (2334) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (2334) mb_port.serial: mbm_rtu@0x3fce9a78, received data: 103 bytes.
D (2344) mbm_rtu@0x3fce9a78:PORT_RECV: 94 43 b9 20 21 52 31 e4 21 84 08 ed 90 87 c5 ce
D (2354) mbm_rtu@0x3fce9a78:PORT_RECV: 04 d5 1a 21 10 14 ad 21 14 a7 21 a7 cd 31 29 2c
D (2364) mbm_rtu@0x3fce9a78:PORT_RECV: 11 31 2d 1c d7 95 a4 85 a6 21 80 0a 8c e4 10 94
D (2364) mbm_rtu@0x3fce9a78:PORT_RECV: a4 af 0f 10 ad 10 21 10 52 42 21 14 95 ad 89 96
D (2374) mbm_rtu@0x3fce9a78:PORT_RECV: 1c 10 8e c7 cd 1d 21 f5 28 fe d5 73 21 8d c6 d6
D (2384) mbm_rtu@0x3fce9a78:PORT_RECV: 88 a3 1c c6 90 00 52 15 31 af 4a 65 18 42 21 84
D (2394) mbm_rtu@0x3fce9a78:PORT_RECV: a7 ca 21 c5 32 31 10
D (2394) mb_port.serial: mbm_rtu@0x3fce9a78, serial processing time[us] = 202573
E (2404) mb_object.master: 0x3fce9a78, drop data received outside of transaction.
D (2414) mb_object.master: 0x3fce9a78:EV_ERROR_PROCESS
D (2414) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (2424) mbm_error_cb_respond_timeout: 04 00 02 00 02
D (2424) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (2434) mb_port.serial: mbm_rtu@0x3fce9a78, uart rx break.
D (2434) mb_object.master: 0x3fce9a78, transaction processing time(us) = 0
D (2444) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (2444) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 119.
D (2454) mb_port.event: mbm_rtu@0x3fce9a78, mb resource release.
D (2474) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (2474) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 31.
D (2474) mb_port.serial: mbm_rtu@0x3fce9a78, frame 150 bytes is ready.
D (2484) mb_object.master: 0x3fce9a78:EV_FRAME_RECEIVED
V (2484) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (2484) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (2494) mb_port.serial: mbm_rtu@0x3fce9a78, uart rx break.
D (2504) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (2514) mb_port.serial: mbm_rtu@0x3fce9a78, received data: 150 bytes.
D (2514) mbm_rtu@0x3fce9a78:PORT_RECV: 94 43 b9 20 21 72 31 e4 21 84 10 d3 21 90 c4 88
D (2524) mbm_rtu@0x3fce9a78:PORT_RECV: 11 d3 9c fe fa 10 b9 64 86 a7 21 9e da 94 86 90
D (2534) mbm_rtu@0x3fce9a78:PORT_RECV: 0d 58 95 fb 14 2c 11 21 18 21 99 86 4a 94 84 cc
D (2534) mbm_rtu@0x3fce9a78:PORT_RECV: fc cf 85 85 a5 a4 0c 28 bc 20 b4 a5 85 8d fd ae
D (2544) mbm_rtu@0x3fce9a78:PORT_RECV: 8f 11 21 70 ae 14 52 cf 84 a4 ae c8 9c fd 09 86
D (2554) mbm_rtu@0x3fce9a78:PORT_RECV: 21 9c 84 a4 96 46 9c 21 85 94 31 29 cd 18 21 b6
D (2564) mbm_rtu@0x3fce9a78:PORT_RECV: 20 a5 cc 21 28 19 72 86 ae 00 1d f6 fa 14 cd 90
D (2574) mbm_rtu@0x3fce9a78:PORT_RECV: a4 46 29 84 84 34 43 b9 21 21 72 95 fa 14 8d 08
D (2574) mbm_rtu@0x3fce9a78:PORT_RECV: dc a4 21 9d 21 a4 ed a5 52 20 08 c6 90 8e e4 4d
D (2584) mbm_rtu@0x3fce9a78:PORT_RECV: b6 4c 31 af 29 ba
D (2594) mb_port.serial: mbm_rtu@0x3fce9a78, serial processing time[us] = 372866
E (2594) mb_object.master: 0x3fce9a78, drop data received outside of transaction.
D (2604) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (2604) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 119.
D (2614) mb_object.master: 0x3fce9a78:EV_ERROR_PROCESS
D (2624) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (2624) mbm_error_cb_respond_timeout: 04 00 02 00 02
D (2634) mb_object.master: 0x3fce9a78, transaction processing time(us) = 0
D (2634) mb_port.event: mbm_rtu@0x3fce9a78, mb resource release.
D (2654) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (2654) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 51.
D (2654) mb_port.serial: mbm_rtu@0x3fce9a78, frame 170 bytes is ready.
D (2664) mb_object.master: 0x3fce9a78:EV_FRAME_RECEIVED
V (2664) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (2674) mb_port.timer: mbm_rtu@0x3fce9a78, timer stopD (2684) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (2684) mb_port.serial: mbm_rtu@0x3fce9a78, uart rx break.
, returns 259.
D (2694) mb_port.serial: mbm_rtu@0x3fce9a78, received data: 170 bytes.
D (2694) mbm_rtu@0x3fce9a78:PORT_RECV: 90 4b 96 9c b6 cd 1d 20 94 31 00 a6 91 c4 9e 16
D (2704) mbm_rtu@0x3fce9a78:PORT_RECV: 48 20 75 08 bb f5 8f 10 c4 62 88 14 43 b9 21 20
D (2714) mbm_rtu@0x3fce9a78:PORT_RECV: 7a 95 fa 14 8d 08 cc 64 14 cd 90 a4 4f 30 c4 ee
D (2724) mbm_rtu@0x3fce9a78:PORT_RECV: 84 a3 18 28 98 94 a5 a4 d4 d9 39 0f cf a4 85 d5
D (2724) mbm_rtu@0x3fce9a78:PORT_RECV: f5 31 0e 10 af a4 21 14 52 42 a6 48 c6 48 a4 0f
D (2734) mbm_rtu@0x3fce9a78:PORT_RECV: 21 14 c4 08 a5 19 a4 af 0e 10 ad 08 a5 cd fd 06
D (2744) mbm_rtu@0x3fce9a78:PORT_RECV: 94 a4 48 29 90 28 8f a5 a4 cd a4 cd 29 8e 94 84
D (2754) mbm_rtu@0x3fce9a78:PORT_RECV: 70 e7 10 52 42 ac 86 a6 91 c4 8e df 91 c2 95 47
D (2764) mbm_rtu@0x3fce9a78:PORT_RECV: 9c 21 10 9e 6d 18 20 14 ad 81 94 31 29 b4 9c 39
D (2764) mbm_rtu@0x3fce9a78:PORT_RECV: dc 28 84 90 f6 4e 86 90 0c 48 90 62 4b d4 d5 1a
D (2774) mbm_rtu@0x3fce9a78:PORT_RECV: 21 78 38 88 94 53 96 cd bc ff
D (2784) mb_port.serial: mbm_rtu@0x3fce9a78, serial processing time[us] = 555181
D (2784) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (2794) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 119.
E (2794) mb_object.master: 0x3fce9a78, drop data received outside of transaction.
D (2804) mb_object.master: 0x3fce9a78:EV_ERROR_PROCESS
D (2814) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (2814) mbm_error_cb_respond_timeout: 04 00 02 00 02
D (2824) mb_object.master: 0x3fce9a78, transaction processing time(us) = 0
D (2824) mb_port.event: mbm_rtu@0x3fce9a78, mb resource release.
D (2844) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (2844) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 60.
D (2844) mb_port.serial: mbm_rtu@0x3fce9a78, frame 179 bytes is ready.
D (2854) mb_object.master: 0x3fce9a78:EV_FRAME_RECEIVED
V (2864) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (2864) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (2874) mb_port.serial: mbm_rtu@0x3fce9a78, received data: 179 bytes.
D (2874) mbm_rtu@0x3fce9a78:PORT_RECV: 94 43 b9 21 21 7a 95 fb 14 bd 1c 88 18 ec 20 93
D (2884) mbm_rtu@0x3fce9a78:PORT_RECV: 21 61 1c 21 d5 00 cc 1d 9d 31 87 84 10 a4 18 29
D (2894) mbm_rtu@0x3fce9a78:PORT_RECV: cd 98 1d 9d 31 a7 14 4b 96 9c 29 dc 85 94 30 29
D (2904) mbm_rtu@0x3fce9a78:PORT_RECV: 2c 10 a3 18 20 98 90 21 a5 8c 06 28 d8 c4 86 90
D (2904) mbm_rtu@0x3fce9a78:PORT_RECV: d5 f4 39 0f a5 b5 a4 dc f5 31 0e 18 8d 9c 20 14
D (2914) mbm_rtu@0x3fce9a78:PORT_RECV: 52 42 ec a6 84 84 a5 94 10 50 a5 84 a4 21 18 20
D (2924) mbm_rtu@0x3fce9a78:PORT_RECV: 98 86 8f e4 18 9b 14 d6 a4 70 cc ca 94 28 0f 85
D (2934) mbm_rtu@0x3fce9a78:PORT_RECV: a5 a5 df a4 af 8e 90 a7 10 10 88 90 11 94 a5 94
D (2944) mbm_rtu@0x3fce9a78:PORT_RECV: 31 1d 21 18 9e 19 dd f5 30 29 ad 88 cc 38 21 21
D (2944) mbm_rtu@0x3fce9a78:PORT_RECV: 86 10 bd 29 cf a6 94 10 da 9c ff da 06 ae f7 31
D (2954) mbm_rtu@0x3fce9a78:PORT_RECV: 84 31 cd 09 ff 10 85 a6 10 86 98 19 21 cd 6d 81
D (2964) mbm_rtu@0x3fce9a78:PORT_RECV: 21 bd fc
D (2964) mb_port.serial: mbm_rtu@0x3fce9a78, serial processing time[us] = 735604
E (2974) mb_object.master: 0x3fce9a78, drop data received outside of transaction.
D (2974) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (2984) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 119.
D (2994) mb_object.master: 0x3fce9a78:EV_ERROR_PROCESS
D (2994) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (3004) mbm_error_cb_respond_timeout: 04 00 02 00 02
D (3004) mb_object.master: 0x3fce9a78, transaction processing time(us) = 0
D (3014) mb_port.event: mbm_rtu@0x3fce9a78, mb resource release.
D (3034) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (3034) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 56.
D (3034) mb_port.serial: mbm_rtu@0x3fce9a78, frame 175 bytes is ready.
D (3044) mb_object.master: 0x3fce9a78:EV_FRAME_RECEIVED
V (3044) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (3054) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (3054) mb_port.serial: mbm_rtu@0x3fce9a78, received data: 175 bytes.
D (3064) mbm_rtu@0x3fce9a78:PORT_RECV: 90 43 b9 20 21 52 31 e4 21 84 08 ed 90 87 c5 88
D (3074) mbm_rtu@0x3fce9a78:PORT_RECV: 11 da 10 af 22 14 ad fb 14 a7 0c 8f cd 54 80 c5
D (3084) mbm_rtu@0x3fce9a78:PORT_RECV: d0 19 33 90 28 ee e4 0c 21 88 4a 29 de 0c 8d f4
D (3084) mbm_rtu@0x3fce9a78:PORT_RECV: 31 0f 8f e6 0a a6 cd 29 04 21 e4 1c a5 10 52 42
D (3094) mbm_rtu@0x3fce9a78:PORT_RECV: 21 a5 85 96 a4 96 1c 10 dc a4 10 94 0d 31 0f 10
D (3104) mbm_rtu@0x3fce9a78:PORT_RECV: ad ad 98 31 52 42 31 85 c4 21 a5 94 10 10 21 8e
D (3114) mbm_rtu@0x3fce9a78:PORT_RECV: 8c 80 ee 20 98 8c 48 a5 34 f2 14 d6 e4 18 29 a4
D (3114) mbm_rtu@0x3fce9a78:PORT_RECV: cd 28 fd 9c 84 8c 90 1c 8f ed 14 29 43 96 86 29
D (3124) mbm_rtu@0x3fce9a78:PORT_RECV: fe 95 da 21 8d e7 08 29 3a 18 1c 21 b5 53 c4 1d
D (3134) mbm_rtu@0x3fce9a78:PORT_RECV: 94 31 31 15 d5 1a 21 00 7a 15 31 af a4 29 c4 84
D (3144) mbm_rtu@0x3fce9a78:PORT_RECV: 29 a4 85 1c ce 91 cc 19 21 cd 6d fd 29 20 ff
D (3144) mb_port.serial: mbm_rtu@0x3fce9a78, serial processing time[us] = 921851
E (3154) mb_object.master: 0x3fce9a78, drop data received outside of transaction.
D (3164) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (3164) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 119.
D (3174) mb_object.master: 0x3fce9a78:EV_ERROR_PROCESS
D (3174) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (3184) mbm_error_cb_respond_timeout: 04 00 02 00 02
D (3194) mb_object.master: 0x3fce9a78, transaction processing time(us) = 0
D (3194) mb_port.event: mbm_rtu@0x3fce9a78, mb resource release.
D (3214) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (3214) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 52.
D (3214) mb_port.serial: mbm_rtu@0x3fce9a78, frame 171 bytes is ready.
D (3224) mb_object.master: 0x3fce9a78:EV_FRAME_RECEIVED
V (3224) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (3234) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (3244) mb_port.serial: mbm_rtu@0x3fce9a78, received data: 171 bytes.
D (3244) mbm_rtu@0x3fce9a78:PORT_RECV: 90 43 b9 20 21 72 31 e4 21 84 0c ed 90 87 c5 88
D (3254) mbm_rtu@0x3fce9a78:PORT_RECV: 11 da 10 af 22 14 ad fb 14 a7 0c 8f cd 54 80 c5
D (3264) mbm_rtu@0x3fce9a78:PORT_RECV: d0 19 33 90 28 ee e4 0c 21 88 4a 29 96 8e 94 fc
D (3274) mbm_rtu@0x3fce9a78:PORT_RECV: af 0f 84 95 85 a5 cd 86 d6 c4 9e 94 14 29 81 ed
D (3274) mbm_rtu@0x3fce9a78:PORT_RECV: 90 a5 a5 a4 ae 21 80 0a 9c 08 85 8c 48 29 04 31
D (3284) mbm_rtu@0x3fce9a78:PORT_RECV: ad 10 ed 10 52 42 31 d4 85 a4 85 94 10 10 21 d4
D (3294) mbm_rtu@0x3fce9a78:PORT_RECV: 0f 8d 48 29 04 21 98 29 94 31 52 42 21 85 a5 a4
D (3304) mbm_rtu@0x3fce9a78:PORT_RECV: a5 06 21 99 10 a5 92 96 f6 31 29 cc c7 20 39 14
D (3304) mbm_rtu@0x3fce9a78:PORT_RECV: a7 10 a4 10 28 29 43 96 04 b6 cd 1d 94 31 31 15
D (3314) mbm_rtu@0x3fce9a78:PORT_RECV: e4 ce 90 01 72 14 31 af 10 29 20 94 04 08 d5 73
D (3324) mbm_rtu@0x3fce9a78:PORT_RECV: 10 af 31 be 21 cd 6d 53 29 21 ff
D (3334) mb_port.serial: mbm_rtu@0x3fce9a78, serial processing time[us] = 1103584
E (3334) mb_object.master: 0x3fce9a78, drop data received outside of transaction.
D (3344) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (3344) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 119.
D (3354) mb_object.master: 0x3fce9a78:EV_ERROR_PROCESS
D (3364) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (3364) mbm_error_cb_respond_timeout: 04 00 02 00 02
D (3374) mb_object.master: 0x3fce9a78, transaction processing time(us) = 0
D (3374) mb_port.event: mbm_rtu@0x3fce9a78, mb resource release.
D (3394) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (3394) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 49.
D (3394) mb_port.serial: mbm_rtu@0x3fce9a78, frame 168 bytes is ready.
D (3404) mb_object.master: 0x3fce9a78:EV_FRAME_RECEIVED
V (3404) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (3414) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (3424) mb_port.serial: mbm_rtu@0x3fce9a78, received data: 168 bytes.
D (3424) mbm_rtu@0x3fce9a78:PORT_RECV: 94 4b 96 9c b6 cd 1d 20 94 31 80 a6 91 c4 9e 16
D (3434) mbm_rtu@0x3fce9a78:PORT_RECV: 48 20 75 08 bb b9 64 28 98 4c 15 cd 5c 80 c4 18
D (3444) mbm_rtu@0x3fce9a78:PORT_RECV: 1a ed a5 90 20 90 9e f5 31 0f 9c 8d 08 9c 34 8f
D (3454) mbm_rtu@0x3fce9a78:PORT_RECV: ed 10 a4 10 96 14 28 fd 29 12 84 41 14 8f ed 98
D (3454) mbm_rtu@0x3fce9a78:PORT_RECV: a5 a5 a5 18 4e 1c 97 10 85 b4 8d b8 29 fd a5 b5
D (3464) mbm_rtu@0x3fce9a78:PORT_RECV: a5 b5 cd 86 d6 18 a5 90 8d 10 52 42 21 a5 a5 94
D (3474) mbm_rtu@0x3fce9a78:PORT_RECV: a4 96 1c 10 39 85 a4 a5 06 20 d8 10 a5 09 8e 9a
D (3484) mbm_rtu@0x3fce9a78:PORT_RECV: 14 d6 48 d0 94 32 a5 90 21 9e c0 8c 38 29 af 8c
D (3484) mbm_rtu@0x3fce9a78:PORT_RECV: 18 20 c7 cd 38 21 20 08 ed 90 87 e5 18 a4 4e 86
D (3494) mbm_rtu@0x3fce9a78:PORT_RECV: 24 0c 80 63 4f 1c 31 1a 98 d9 31 84 3c dd 29 c6
D (3504) mbm_rtu@0x3fce9a78:PORT_RECV: de 21 a4 d6 dc af 4a 9e
D (3504) mb_port.serial: mbm_rtu@0x3fce9a78, serial processing time[us] = 1284327
E (3514) mb_object.master: 0x3fce9a78, drop data received outside of transaction.
D (3524) mb_object.master: 0x3fce9a78:EV_ERROR_PROCESS
D (3524) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (3534) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 119.
D (3544) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (3544) mb_port.serial: mbm_rtu@0x3fce9a78, uart rx break.
D (3554) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (3554) mbm_error_cb_respond_timeout: 04 00 02 00 02
D (3564) mb_object.master: 0x3fce9a78, transaction processing time(us) = 0
D (3564) mb_port.event: mbm_rtu@0x3fce9a78, mb resource release.
D (3584) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (3584) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 59.
D (3584) mb_port.serial: mbm_rtu@0x3fce9a78, frame 178 bytes is ready.
D (3594) mb_object.master: 0x3fce9a78:EV_FRAME_RECEIVED
V (3594) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (3604) mb_port.timer: mbm_rtu@0x3fce9a78, timer stopD (3614) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (3614) mb_port.serial: mbm_rtu@0x3fce9a78, uart rx break.
, returns 259.
D (3624) mb_port.serial: mbm_rtu@0x3fce9a78, received data: 178 bytes.
D (3624) mbm_rtu@0x3fce9a78:PORT_RECV: 9c 4b 96 9c b6 cd 1d 20 94 31 80 a6 91 c4 9e 16
D (3634) mbm_rtu@0x3fce9a78:PORT_RECV: 48 20 75 08 bb f5 8f 10 c4 62 88 14 63 96 86 31
D (3644) mbm_rtu@0x3fce9a78:PORT_RECV: 65 cd 1d 21 18 48 8e cd 86 d6 08 a6 10 ac 14 52
D (3654) mbm_rtu@0x3fce9a78:PORT_RECV: 42 21 a5 95 92 a4 96 1c 10 29 85 10 80 ee 20 58
D (3654) mbm_rtu@0x3fce9a78:PORT_RECV: 8e ce b5 a4 cd 14 d6 c4 18 e5 8e c4 28 fd d0 8e
D (3664) mbm_rtu@0x3fce9a78:PORT_RECV: 48 a5 cd 86 d6 21 85 18 ed 10 52 42 21 a5 85 a4
D (3674) mbm_rtu@0x3fce9a78:PORT_RECV: a4 06 21 99 96 54 94 a4 fc af 0f 10 21 ac 72 90
D (3684) mbm_rtu@0x3fce9a78:PORT_RECV: 8f ed 10 85 a4 4e 31 29 cd 29 21 10 bd 29 cf a6
D (3694) mbm_rtu@0x3fce9a78:PORT_RECV: 94 10 72 86 af 00 94 f6 31 29 ad 48 94 31 29 bd
D (3694) mbm_rtu@0x3fce9a78:PORT_RECV: 9c 29 14 ec 21 20 52 30 ec 21 21 0c 31 5a 28 08
D (3704) mbm_rtu@0x3fce9a78:PORT_RECV: 47 90 9f 04 4b d5 72 86 af c6 39 2d 14 53 96 c6
D (3714) mbm_rtu@0x3fce9a78:PORT_RECV: 08 ff
D (3714) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (3724) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 119.
D (3724) mb_port.serial: mbm_rtu@0x3fce9a78, serial processing time[us] = 1485520
E (3734) mb_object.master: 0x3fce9a78, drop data received outside of transaction.
D (3744) mb_object.master: 0x3fce9a78:EV_ERROR_PROCESS
D (3744) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (3754) mbm_error_cb_respond_timeout: 04 00 02 00 02
D (3754) mb_object.master: 0x3fce9a78, transaction processing time(us) = 0
D (3764) mb_port.event: mbm_rtu@0x3fce9a78, mb resource release.
D (3784) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (3784) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 66.
D (3784) mb_port.serial: mbm_rtu@0x3fce9a78, frame 185 bytes is ready.
D (3794) mb_object.master: 0x3fce9a78:EV_FRAME_RECEIVED
V (3794) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (3804) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (3804) mb_port.serial: mbm_rtu@0x3fce9a78, received data: 185 bytes.
D (3814) mbm_rtu@0x3fce9a78:PORT_RECV: 98 43 b9 21 21 5a 95 fb 14 bd 1c 88 18 ec 20 93
D (3824) mbm_rtu@0x3fce9a78:PORT_RECV: 21 51 1c 21 d5 00 cc 1d 9d 31 87 84 10 a4 18 29
D (3834) mbm_rtu@0x3fce9a78:PORT_RECV: cd 98 1d 9d 31 a7 14 4b 96 9c 29 dc 85 94 30 29
D (3834) mbm_rtu@0x3fce9a78:PORT_RECV: 2c 10 a3 18 20 18 90 21 a5 8c 06 28 d8 c4 86 10
D (3844) mbm_rtu@0x3fce9a78:PORT_RECV: dd f4 39 0f a4 85 a5 53 fc af 0e 10 e4 a4 a6 10
D (3854) mbm_rtu@0x3fce9a78:PORT_RECV: 52 42 8f 18 d6 e6 c4 28 0f a5 c5 a5 01 a4 af 8e
D (3864) mbm_rtu@0x3fce9a78:PORT_RECV: 14 85 33 a6 10 52 42 a7 08 86 4a a5 0f 21 14 d4
D (3864) mbm_rtu@0x3fce9a78:PORT_RECV: 94 98 94 f5 31 0e 90 a5 10 a7 10 52 42 e5 b4 a4
D (3874) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (3884) mb_port.serial: mbm_rtu@0x3fce9a78, uart rx break.
D (3884) mbm_rtu@0x3fce9a78:PORT_RECV: a5 0c 21 b5 20 39 15 ec 21 21 52 95 fa 14 bd 9c
D (3894) mbm_rtu@0x3fce9a78:PORT_RECV: 29 43 96 86 29 fe ad cd 75 29 ce 31 28 88 dc 10
D (3904) mbm_rtu@0x3fce9a78:PORT_RECV: 06 11 0d 30 5a 21 1b 95 38 42 31 a5 84 a6 19 86
D (3914) mbm_rtu@0x3fce9a78:PORT_RECV: 91 d6 90 31 6d 80 a4 bc fc
D (3914) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (3924) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 119.
D (3924) mb_port.serial: mbm_rtu@0x3fce9a78, serial processing time[us] = 1671586
E (3934) mb_object.master: 0x3fce9a78, drop data received outside of transaction.
D (3944) mb_object.master: 0x3fce9a78:EV_ERROR_PROCESS
D (3944) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (3954) mbm_error_cb_respond_timeout: 04 00 02 00 02
D (3954) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (3964) mb_port.serial: mbm_rtu@0x3fce9a78, uart rx break.
D (3964) mb_object.master: 0x3fce9a78, transaction processing time(us) = 0
D (3974) mb_port.event: mbm_rtu@0x3fce9a78, mb resource release.
D (3994) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (3994) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 77.
D (3994) mb_port.serial: mbm_rtu@0x3fce9a78, frame 196 bytes is ready.
D (4004) mb_object.master: 0x3fce9a78:EV_FRAME_RECEIVED
V (4004) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (4014) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (4014) mb_port.serial: mbm_rtu@0x3fce9a78, received data: 196 bytes.
D (4024) mbm_rtu@0x3fce9a78:PORT_RECV: 9c 43 b9 20 21 52 31 e4 21 84 0c c6 90 87 c5 88
D (4034) mbm_rtu@0x3fce9a78:PORT_RECV: 11 db 10 af 22 14 ad fb 14 a7 0c 8f cd 54 80 c5
D (4034) mbm_rtu@0x3fce9a78:PORT_RECV: d0 19 32 90 28 ee e4 0c 21 88 4a 29 de 0c 8d ee
D (4044) mbm_rtu@0x3fce9a78:PORT_RECV: 21 99 c4 9e 94 10 cd 86 d6 14 9e 08 a4 0c 21 88
D (4054) mbm_rtu@0x3fce9a78:PORT_RECV: 0a 29 9c 96 a4 96 1c 10 9c 84 18 80 ee 20 d8 52
D (4064) mbm_rtu@0x3fce9a78:PORT_RECV: 1c ac 00 cd 29 fd 84 84 8d b5 cd 28 fd dc 90 8e
D (4074) mbm_rtu@0x3fce9a78:PORT_RECV: 84 1c 43 b9 28 20 10 8f 11 31 c6 31 2d ed 52 94
D (4074) mbm_rtu@0x3fce9a78:PORT_RECV: 91 a5 a4 0f 21 14 90 21 ae d6 f5 31 0e 10 29 84
D (4084) mbm_rtu@0x3fce9a78:PORT_RECV: a5 cd fd 06 90 21 72 95 f2 14 ad 48 94 30 29 bd
D (4094) mbm_rtu@0x3fce9a78:PORT_RECV: 9c 29 1d ec 21 fd 18 95 72 86 ae 85 90 84 1c da
D (4104) mbm_rtu@0x3fce9a78:PORT_RECV: 10 af 00 f0 18 f3 14 cd b7 0a ee 15 44 a5 cd 1d
D (4104) mbm_rtu@0x3fce9a78:PORT_RECV: 20 b4 29 98 43 15 86 29 34 d5 fe df 94 21 a4 ef
D (4114) mbm_rtu@0x3fce9a78:PORT_RECV: 28 21 7e e4
D (4114) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (4124) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 119.
D (4134) mb_port.serial: mbm_rtu@0x3fce9a78, serial processing time[us] = 1880670
E (4134) mb_object.master: 0x3fce9a78, drop data received outside of transaction.
D (4144) mb_object.master: 0x3fce9a78:EV_ERROR_PROCESS
D (4154) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (4154) mbm_error_cb_respond_timeout: 04 00 02 00 02
D (4164) mb_object.master: 0x3fce9a78, transaction processing time(us) = 0
D (4164) mb_port.event: mbm_rtu@0x3fce9a78, mb resource release.
D (4184) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (4184) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 63.
D (4184) mb_port.serial: mbm_rtu@0x3fce9a78, frame 182 bytes is ready.
D (4194) mb_object.master: 0x3fce9a78:EV_FRAME_RECEIVED
V (4194) mb_port.serial: mbm_rtu@0x3fce9a78: take RX semaphore (100 ticks).
D (4204) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (4214) mb_port.serial: mbm_rtu@0x3fce9a78, received data: 182 bytes.
D (4214) mbm_rtu@0x3fce9a78:PORT_RECV: 98 43 b9 20 21 72 31 e4 21 84 0c ed 90 87 c5 88
D (4224) mbm_rtu@0x3fce9a78:PORT_RECV: 11 da 10 af 22 14 ad fb 14 a7 0c 8f cd 54 80 c5
D (4234) mbm_rtu@0x3fce9a78:PORT_RECV: d0 19 f4 38 21 21 e4 0c 21 88 4a 29 96 53 29 ee
D (4244) mbm_rtu@0x3fce9a78:PORT_RECV: 21 99 91 95 85 a5 cd 86 d6 c4 9e 94 14 29 81 ed
D (4244) mbm_rtu@0x3fce9a78:PORT_RECV: 10 a4 a5 85 a5 06 21 19 d4 08 a5 36 98 29 04 70
D (4254) mbm_rtu@0x3fce9a78:PORT_RECV: a6 94 20 14 52 42 21 94 a4 a7 a5 94 10 18 29 dc
D (4264) mbm_rtu@0x3fce9a78:PORT_RECV: 84 94 fc af 8f 14 a5 1a cd 10 52 42 21 94 a5 a5
D (4274) mbm_rtu@0x3fce9a78:PORT_RECV: 18 96 1c 10 ce 0a b4 21 f6 1f 97 84 b5 a4 18 4e
D (4274) mbm_rtu@0x3fce9a78:PORT_RECV: 1c 97 96 45 99 29 20 11 b9 20 14 bd 94 38 43 b9
D (4284) mbm_rtu@0x3fce9a78:PORT_RECV: 21 38 dd b4 08 dc 29 c6 20 8d 19 e4 ce 90 01 72
D (4294) mbm_rtu@0x3fce9a78:PORT_RECV: 14 31 af 10 29 30 94 04 08 d5 e4 ce 90 cc 18 21
D (4304) mbm_rtu@0x3fce9a78:PORT_RECV: cd 6d 53 29 21 ff
D (4304) mb_port.serial: mbm_rtu@0x3fce9a78, serial processing time[us] = 2074903
E (4314) mb_object.master: 0x3fce9a78, drop data received outside of transaction.
D (4314) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (4324) mb_port.serial: mbm_rtu@0x3fce9a78, data event, len: 119.
D (4334) mb_object.master: 0x3fce9a78:EV_ERROR_PROCESS
D (4334) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
D (4344) mbm_error_cb_respond_timeout: 04 00 02 00 02
D (4344) mb_port.serial: mbm_rtu@0x3fce9a78, UART[2] event:
D (4354) mb_port.serial: mbm_rtu@0x3fce9a78, uart rx break.
D (4354) mb_object.master: 0x3fce9a78, transaction processing time(us) = 0
D (4364) mb_port.event: mbm_rtu@0x3fce9a78, mb resource release.
I (4374) MASTER_TEST: Destroy master...
V (4374) mbc_serial.master: mb stack is active, try to disable.
D (4384) mb_port.serial: mbm_rtu@0x3fce9a78, suspend port.
D (4384) mb_port.timer: mbm_rtu@0x3fce9a78, timer stop, returns 259.
V (4394) intr_alloc: esp_intr_free: Disabling int, killing handler
D (4394) mb_object.master: Close mbm_rtu@0x3fce9a78 command handlers.
D (4404) MB_FUNC_HANDLING: Inst: 0x3fce9a78, close handler: 0x2, 0x4200de10
--- 0x4200de10: mbm_fn_read_discrete_inputs at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfuncdisc_master.c:88
D (4414) MB_FUNC_HANDLING: Inst: 0x3fce9a78, close handler: 0xf, 0x4200dcd4
--- 0x4200dcd4: mbm_fn_write_multi_coils at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfunccoils_master.c:286
D (4414) MB_FUNC_HANDLING: Inst: 0x3fce9a78, close handler: 0x5, 0x42020c40
--- 0x42020c40: mbm_fn_write_coil at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfunccoils_master.c:207
D (4424) MB_FUNC_HANDLING: Inst: 0x3fce9a78, close handler: 0x1, 0x4200daa4
--- 0x4200daa4: mbm_fn_read_coils at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfunccoils_master.c:106
D (4434) MB_FUNC_HANDLING: Inst: 0x3fce9a78, close handler: 0x17, 0x4200e330
--- 0x4200e330: mbm_fn_rw_multi_holding_regs at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfuncholding_master.c:416
D (4434) MB_FUNC_HANDLING: Inst: 0x3fce9a78, close handler: 0x6, 0x4200df40
--- 0x4200df40: mbm_fn_write_holding_reg at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfuncholding_master.c:119
D (4444) MB_FUNC_HANDLING: Inst: 0x3fce9a78, close handler: 0x10, 0x4200e07c
--- 0x4200e07c: mbm_fn_write_multi_holding_reg at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfuncholding_master.c:206
D (4454) MB_FUNC_HANDLING: Inst: 0x3fce9a78, close handler: 0x3, 0x4200e198
--- 0x4200e198: mbm_fn_read_holding_reg at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfuncholding_master.c:297
D (4454) MB_FUNC_HANDLING: Inst: 0x3fce9a78, close handler: 0x4, 0x4200e484
--- 0x4200e484: mbm_fn_read_inp_reg at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfuncinput_master.c:91
D (4464) MB_FUNC_HANDLING: Inst: 0x3fce9a78, close handler: 0x11, 0x4200e638
--- 0x4200e638: mbm_fn_report_slave_id at /home/tiago/Documentos/PlatformIO/Projects/esp-idf-touch-modbus/managed_components/espressif__esp-modbus/modbus/mb_objects/functions/mbfuncother.c:100
I (4474) main_task: Returned from app_main()
```

# Log no USR-TCP232-410s

```
Enviado pelo ESP32: 0x64 0x4 0x0 0x0 0x0 0x2 0x78 0x3e 
Resposta do dispositivo MODBUS: 0x64 0x4 0x4 0xae 0x14 0x41 0x91 0x5f 0x92  
Enviado pelo ESP32: 0x64 0x4 0x0 0x2 0x0 0x2 0xd9 0xfe 
Resposta do dispositivo MODBUS: 0x64 0x4 0x4 0xb 0xf3 0x42 0x89 0xcd 0x93
```