// SPDX-License-Identifier: zlib-acknowledgement

#include "emt.h"

int
get_fib(int num)
{
  int cur = 1, next = 1, temp = 0;

  if (num < 0 || num >= FIB_OVERFLOW_NUM) return 0;

  if (num == 0 || num == 1) return 1;

  for (int cursor = 2; cursor <= num; ++cursor)
  {
    temp = cur;
    cur = next;
    next += temp;
  }

  return next;
}
