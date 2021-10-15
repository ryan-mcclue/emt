<!-- SPDX-License-Identifier: zlib-acknowledgement -->
THE HARDEST THING IN SOFTWARE IS NOT TO OVERCOMPLICATE

Unit and integration tests are to be done in software (as we have more control, e.g. in hardware we can't simulate malformed pin states, resets, etc.)
There is little point in writing tests for bare metal in renode, as you require the hardware to write a driver and once it works, it works.
System/acceptence tests are for hardware (or could be done with Renode).

UNIT TEST TYPES:
state based testing good for independent modules, e.g. math functions, drivers, storage modules
interaction based testing good for modules that glue things together

1. Perform green-field testing (concerns with black box vs white box come later)
Naming based on behaviour, e.g. test_Input0ShouldReturn10, etc. 
(or test_Input0_should_Return10, test_SetPinAsOutput_SHOULD_NotUpdateDirection_WHEN_PinIsNotValid)
Once specifics are done do general, e.g. test_InputNShouldReturnValidResponse

2. Perform error conditions. How these errors are handled is determined by product requirements,
company policy (all errors are logged to a file) and finally falling back on your own judgement
e.g. test_NegativeInputReturns0, test_InputsThatOverflowReturn0 (test one before limit as well)
limits.h should be used, and possibly spreadsheet calculations.
If making an assumption about the platform, e.g. sizeof(int), put that in an assertion
