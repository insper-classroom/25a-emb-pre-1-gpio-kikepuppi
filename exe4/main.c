#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

int BTN_PIN = 28;
int LED_PIN1 = 5;
int LED_PIN2 = 8;
int LED_PIN3 = 11;
int LED_PIN4 = 15;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  // Led 1
  gpio_init(LED_PIN1);
  gpio_set_dir(LED_PIN1, GPIO_OUT);

  // Led 2
  gpio_init(LED_PIN2);
  gpio_set_dir(LED_PIN2, GPIO_OUT);

  // Led 3
  gpio_init(LED_PIN3);
  gpio_set_dir(LED_PIN3, GPIO_OUT);

  // Led 4
  gpio_init(LED_PIN4);
  gpio_set_dir(LED_PIN4, GPIO_OUT);

  while (true) {
    // Use delay de 300 ms entre os estados!

    if (!gpio_get(BTN_PIN)) {

      gpio_put(LED_PIN1, 1);
      sleep_ms(300);
      gpio_put(LED_PIN1, 0);
      gpio_put(LED_PIN2, 1);
      sleep_ms(300);
      gpio_put(LED_PIN2, 0);
      gpio_put(LED_PIN3, 1);
      sleep_ms(300);
      gpio_put(LED_PIN3, 0);
      gpio_put(LED_PIN4, 1);
      sleep_ms(300);
      gpio_put(LED_PIN4, 0);
      
      while (!gpio_get(BTN_PIN)) {
      };
    }

  }
}
