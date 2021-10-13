TODO(Ryan): Difference between CMSIS and HAL? BSP also

TODO(Ryan): When are external devices like JTAG/SWD adapters required?
When the board does not have an integrated/on-board debugger, e.g. Atmel EDBG
On page 19, Section Debug Interface, says exposes SWD interface. 
So, if not on-board/integrated debugger, cannot debug? What exactly does it mean when it has
an onboard debugger, does that mean it supports the JTAG/SWD protocol?

Then says to use JLink JTAG/SWD debugger, but then require a adapter cable for JTAG to SWD?
Mentions about openOCD not being able to reset before debugging, so use JLink. 
Is the JLink just a commercial openOCD? It must be different as its a physical device...

(cortex-m coresight architecture)
Arm debug interface architecture. Implementation is Debug Access Port.
Through the debug port are access ports. Access ports expose various registers. 
Debug port can use various protocols. 
JTAG is available in most silicon (standardised in 1990). SWD requires less exposed pins
than JTAG. SWD/JTAG is both (most commonly seen in modern MCUs)
Require an interfacing MCU, i.e. something to map SWD/JTAG to a USB protocol. This could be
a dongle or an IC on the board. Can use CMSIS-DAP to run on another MCU, however perhaps
easiest to use SEGGER J-Link or ST-Link
Ideally want the debug probe to implement RTOS Awareness, e.g. retrieving threads  

TODO(Ryan): DSP importance.

Writing directly to registers instead of using arduino library is much faster.

1. **STARTUP**:
  1. Compile with BSP linker script and startup file
  2. Obtain ISA, CPU, MCU technical reference manuals.
     Obtain board schematics

MCU has boot up sequence (typically found in memory map section). It seems
that most MCUs have preloaded bootloader. 
Seems bootloaders do two things: copy from ROM to RAM or load from
peripheral (UART, USB, etc). Could also unpack ELF file, however usually just
a binary file.
Initial IP will Reset_Handler from .isr_vector
(One reason for using C is that it maps very closely to executable structure)

In reality, all we need is some C code and a linker script to write a
monolithic firmware for our microcontroller. However, it's recommended to
use a bootloader to decouple.

The CPU architecture will have an exception (a cpu interrupt) model.
Here, reset behaviour will be defined.
For ARMV7 we see that VTOR is 0x000, disable all interrupts/exceptions,
load SP from 0x000 and load PC from 0x0004 (we find that the symbol here:
Reset_Handler, is 1 bit lower than expected as lowest bit of interworking 
address indicates Thumb instructions to be used)
TODO(Ryan): Investigate usage of various binutils programs $(nm), etc. 
For raw bytes: $(xxd main.bin), for structure: $(objdump -t main.axf)
Where is information relating to what the reset handler should do?


Why do our programs contain startup assembly? What are they doing?
CPU has reset vector (what section in docs?)

The MCU may have boot loader in flash memory, or as part of 'internal rom',
i.e. memory not included in the 'user memory'. The boot loader is a bit of a
misnomer as it can also be application-initiated to perform firmware updates.
In addition to a boot loader, the MCU may have other software present, e.g.
driver library, AES, CRC etc. 


boot fuse redirect reset vector?
when flashing data over USB (virtual COM port?), are we instructing the boot
loader to erase/load the data?
so, the bootloader determines what type of flashing program to use, e.g LM
Flasher as it will issue a particular UART, SPI interface command? How does
this 'polling' behaviour align with boot loader name?
so, if we corrupt the boot loader we will need to use some external device to
reflash the boot loader correctly (ICSP pins, in circuit serial programming)
3rd party vendors will create devices that handle the intricacies of this for
us. why do they give us a default bootloader and not let us just flash
directly?
tie resistor to reset pin to allow for toggling?



INVESTIGATE SERIES OF 3 BOOKS: Embedded Systems: Real-Time Operating Systems for ARM Cortex-M Microcontrollers

ORGANISE INTO HEADERS

tiva c series board (led switches, convenient pin-outs, power switches, ports,
etc; arduino is board employing atmega MCU) employs tiva tm4c123g MCU with
DMA, SAR ADC, CAN modules, SPI/UART/I2C (are these features of MCU or board?)
the 32 bit arm cortex-m4 has FPU (a series in phones, m for microcontroller, r
also in some phones)
it is labelled as an evaluation board? (does this refer to the IDCI?)
MCU has eeprom / flash (nand or nor flash; subset of eeprom; so when say ROM,
essentially mean flash) / sram memory.
as often harvard archicture (why?) different memory types employed.
memoy degradation/life cycle dffers between them?
CAN (controller area network), controls nodes (electronic control units). Used
as different ECUs can be added/removed to communicate similarly over the CAN
(used in cars)
board uses stellaris ICDI (ST-link is for stm32 mcus)

twos complement!
hex digit to nibble
precision is number of values (determined by number of bits available)
is fixed point used anymore?

IMPORTANT FEATURES: testability, size, power, cost, real time 

Von Neumann, RAM (variables, data, stack) + ROM (code/constants) + I/O all on same CPU bus.
Harvard has ICode bus for ROM, and a SystemBus for RAM + I/O. This allows
operations to occur simultaneously. So, why use Von Neumann?

The cortex M has I/O ports, e.g. Port A, port B, etc. these ports have a number
of pins on each (so a port is just a collection of pins) 
If parallel, can set all these pins/bits at the same time.
Serial single bit at a time (used for communicating with other devices).
Analog used to measure real world, or output signals
Time another type of I/O.

ISA contains instructions, registers (general, special), addressing modes (how to fetch
operands), memory accesses (x86, arm, powerpc (automobiles), SPARC (servers)) 
Stack allows to write modular code
ARM has link register that holds return address of routine
Status register has particular bits, e.g. Z bit for zero 
Cortex-M executes Thumb instructions
Listing file is combined source and object code  
INSTRUCTION TYPES:
Memory access (mov), ALU (sub, add), control (bne), special (interrupts, etc.)

Memory map will be RAM + ROM + External I/O + Internal I/O
memory mapped i/o address may refer to pin or a device register
also have internal i/o memory map?

A driver is software that facilitates the use of an I/O port.

SRAM typically uses 6 MOSFET (metal oxide semiconductor field effect
transistor) to create each memory bit. The different types of memory are

Without Keil, require LM Flash programmer, some JTAG interface/stelllaris
driver for gdb?

have processor registers and device registers (to activate clock for particular port/gpio)
CMSIS for cortex-m?

High impedance pin has indeterminate state, i.e. neither high nor low, a.k.a
tri-stated/floating (it will read 0V not because it is low, but because it is not connected to anything). 
HiZ/tri-state pins exist so as to allow the pin to act as input and output.
To avoid power dissipation and unknown state, drive with external source, e.g. ground or voltage.
Pull-up resistor connected to voltage, pull-down to ground.
Without a pull-up resistor, circuit may short.
TODO(Ryan): open-drain?


-------------------------------------------------------------------------------------------------------------------------------
ENTREPRENEUR:
idea -> validate -> deliver -> manage.
subscriptions formalise a long term relationship. Can focus on DO + SELL once rather than
DO + SELL and make developments to provide continual use for the customer.
Easier to ascertain what your customer's want and not having to stress or
spend large amounts of time/money to acquire new customers.
Can add things like discounts + promotional items to entice the customer to
buy the subscription. The customer obtaining the subscription is the main
focus. Peripherals introduced to structure the offer in an attractive way.
TODO(Ryan): Investigate various subscription models

ELECTRONICS:
MULTIMETER:
4000 count means can display 3.999. Therefore, left most digit can never be 4.
The decimal place will shift over when needing to display higher than 4V
Autoranging means this will happen automatically and we won't have to
explicitly select the voltage range we are in.
True RMS means can accurately read non-sinusoidal wave forms
