// SPDX-License-Identifier: zlib-acknowledgement

// values to test for unsigned as these can be problematic working with signed and unsigned: 0x80 (10000000), 0x7f (01111111), 0xff

// feedback functions can smooth out noisy input, e.g. low-pass filter

// if build machine has different word size to target, may run into issues with integer
// promotion and subsequent overflow in mathematical functions. 
// this is where simulators can help

// take previous input as arg and have caller handle this instead of local persist
void
low_pass_filter(u16 prev_val, u16 new_val)
{

}
