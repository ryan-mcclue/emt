// SPDX-License-Identifier: zlib-acknowledgement

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

void
test(void **state)
{
  assert_true(0);
}

int
main(void)
{
  const struct CMUnitTest tests[] =
  {
    cmocka_unit_test(test),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
