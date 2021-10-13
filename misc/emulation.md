<!-- SPDX-License-Identifier: zlib-acknowledgement -->
qemu suited for higher level, e.g. linux. supports minimal cortex-M series

serial over UART

mach create
WE COULD SPECIFY EACH BUS AND PERIPHERAL BY HAND
machine LoadPlatformDescription @platforms/boards/stm32f4_discovery-kit.repl
COULD ALSO LoadBinary
sysbus LoadELF @example.elf
VARIOUS PERIPHERALS HAVE 'ANALYZERS'
showAnalyzer sysbus.uart2
start
quit
