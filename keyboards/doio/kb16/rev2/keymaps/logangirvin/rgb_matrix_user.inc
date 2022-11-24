
// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(gaming)
RGB_MATRIX_EFFECT(chatting)
RGB_MATRIX_EFFECT(none)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e.g: A simple effect, self-contained within a single method
static bool gaming(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
    rgb_matrix_set_color(6, 0xff, 0xff, 0x00);
    rgb_matrix_set_color(9, 0xff, 0xff, 0x00);
    rgb_matrix_set_color(10, 0xff, 0xff, 0x00);
    rgb_matrix_set_color(11, 0xff, 0xff, 0x00);
  return rgb_matrix_check_finished_leds(led_max);
}

// e.g: A more complex effect, relying on external methods and state, with
// dedicated init and run methods
static uint8_t value;
static uint8_t delta;
static void chatting_complex_init(effect_params_t* params) {
  value = 0;
  delta = 1;

  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
  }

  rgb_matrix_set_color(8, 88, 101, 242);
  rgb_matrix_set_color(11, 255, 128, 0x00);

  rgb_matrix_set_color(12, 184, 182, 180);
  rgb_matrix_set_color(14, 255, 128, 0x00);
  rgb_matrix_set_color(15, 128, 0x00, 0x00);
}
static bool chatting_complex_run(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  if (value == 0xff) {
    delta = -1;
  } else if (value == 0x00) {
    delta = 1;
  }
  value += delta;

  rgb_matrix_set_color(0, value, 0x00, 0x00);
  rgb_matrix_set_color(1, value, 0x00, 0x00);
  rgb_matrix_set_color(2, 0x00, 0xff - value, 0x00);
  rgb_matrix_set_color(3, 0x00, 0xff - value, 0x00);

  rgb_matrix_set_color(4, value, 0x00, 0x00);
  return rgb_matrix_check_finished_leds(led_max);
}
static bool chatting(effect_params_t* params) {
  if (params->init) chatting_complex_init(params);
  return chatting_complex_run(params);
}

// e.g: A simple effect, self-contained within a single method
static bool none(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  return rgb_matrix_check_finished_leds(led_max);
}

#endif