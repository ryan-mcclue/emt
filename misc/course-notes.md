<!-- SPDX-License-Identifier: zlib-acknowledgement -->
Unit tests are to be done in software.
System tests are for hardware (or could be done with Renode)

1. Perform green-field testing (concerns with black box vs white box come later)
Naming based on behaviour, e.g. test_Input0ShouldReturn10, etc.
Once specifics are done do general, e.g. test_InputNShouldReturnValidResponse

2. Perform error conditions. How these errors are handled is determined by product requirements,
company policy (all errors are logged to a file) and finally falling back on your own judgement
e.g. test_NegativeInputReturns0, test_InputsThatOverflowReturn0 (limits.h should be used)
