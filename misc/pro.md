<!-- SPDX-License-Identifier: zlib-acknowledgement -->

TODO(Ryan): Obtain STM32 and use RTOS on it

SD (secure digital) used in embedded for its low-power, low-cost, etc.
A possible SD bus is SDIO (SPI simpler but slower)
USB-FS (full speed, i.e. 1.0) and USB-CDC (communication, e.g. network card) 
FATfs embedded filesystem

CI means to regularly integrate code into mainline repository, i.e. merging into master
Require automated builds and tests to achieve this. 
Although an investment is required, forces a level of discipline required to ensure a codebase
can grow and work well at scale.

TODO(Ryan): In unit-test basics, makes distinction between embedded software and firmware.
Is this RTOS and bare-metal? Use renode for bare-metal?
