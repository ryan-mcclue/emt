// SPDX-License-Identifier: zlib-acknowledgement

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

static void
test_TheFirst(void **cmocka_state)
{
  assert_true(1 == 1);
}

int 
main(void)
{
	const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_TheFirst),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
