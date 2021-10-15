// SPDX-License-Identifier: zlib-acknowledgement

typedef reg volatile u32;

typedef volatile struct
{
  reg pdor;
  reg psor;
} GPIOReg;

#define BIT_TO_MASK(bit) \
  (1U << (bit))

#if defined(NATIVE_TESTING)
  GPIOReg PORTA;
#else
  #define PORTA ((GPIOReg *)(0x400FF000U))
  // PORTA->pdor = BIT_TO_MASK(0); 
#endif

#define GPIO_OK 0

int
gpio_set_pin_as_output(u8 pin)
{
  // pdor |= BIT_TO_MASK(1);
  // IMPORTANT(Ryan): Shifting by more than size is undefined, could even rotate
  return GPIO_OK;
}

void
test_SetGPIOPinAsOutput_SHOULD_ConfigurePinDirection(void)
{
  PORTA->pdor = 0;

  gpio_set_pin_as_output(0);
  assert_int_equal(PORTA.pdor, BIT_TO_MASK(0));

  gpio_set_pin_as_output(31);
  assert_int_equal(PORTA.pdor, BIT_TO_MASK(0) | BIT_TO_MASK(31));
}

void
gpio_set_pin_as_input(u8 pin)
{
  // pdor &= ~(BIT_TO_MASK(1));
}

void
test_SetGPIOPinAsInput_SHOULD_ConfigurePinDirection(void)
{
  PORTA->pdor = -1;

  gpio_set_pin_as_input(0);
  assert_int_equal(PORTA.pdor, ~(BIT_TO_MASK(0)));

  gpio_set_pin_as_input(31);
  assert_int_equal(PORTA.pdor, ~(BIT_TO_MASK(0) | BIT_TO_MASK(31)));
}
