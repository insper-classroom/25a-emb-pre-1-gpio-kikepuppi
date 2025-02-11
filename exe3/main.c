#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_RED = 28;
const int BTN_GREEN = 26;

const int LED_PIN_R = 4;
const int LED_PIN_G = 6;

int main() {
  stdio_init_all();

  gpio_init(BTN_RED);
  gpio_set_dir(BTN_RED, GPIO_IN);
  gpio_pull_up(BTN_RED);

  gpio_init(BTN_GREEN);
  gpio_set_dir(BTN_GREEN, GPIO_IN);
  gpio_pull_up(BTN_GREEN);

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  int red = 0, green = 0;

  while (true) {

    if (!gpio_get(BTN_RED)) {

      if (red) {
        gpio_put(LED_PIN_R, 0);
        red = 0;
      } else {
        gpio_put(LED_PIN_R, 1);
        red = 1;
      }

      while (!gpio_get(BTN_RED)) {
      };
    }

    if (!gpio_get(BTN_GREEN)) {
      
      if (green) {
        gpio_put(LED_PIN_G, 0);
        green = 0;
      } else {
        gpio_put(LED_PIN_G, 1);
        green = 1;
      }

      while (!gpio_get(BTN_GREEN)) {
      };
    }
  }
}
