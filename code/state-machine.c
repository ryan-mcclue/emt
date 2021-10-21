// SPDX-License-Identifier: zlib-acknowledgement

// IMPORTANT(Ryan): This is to give our tests access to global state via extern
#if !defined(TESTING)
  #define STATIC static
#else
  #define STATIC
#endif

extern ParserState state;

void
test_ParserAddChar_SHOULD_StartLookingForBracket(void **state)
{
  state = PARSER_STATE_LOOKING_FOR_START;
  test_assert_null(parser_add_char(']'));
  test_assert_equal(state, PARSE_STATE_LOOKING_FOR_CMD);
}

void test_ParserAddChar_SHOULD_Reject/IgnoreInvalidCharacter(void **state) {}
void test_ParserAddChar_SHOULD_AcceptALengthOfZero(void **state) {}

// NOTE(Ryan): Black box tests
void test_ParserAddChar_SHOULD_HandleValidPacketWithData(void **state) {}
