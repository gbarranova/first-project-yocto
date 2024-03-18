#include <gpiod.h>
#include <stdio.h>

void main(void) {
  struct gpiod_chip *chip;
  struct gpiod_line *LED1;
  struct gpiod_line *LED2;
  struct gpiod_line *LED3;
  struct gpiod_line *LED4;

  chip = gpiod_chip_open_by_name("gpiochip0");
  LED1 = gpiod_chip_get_line(chip, 200);
  LED2 = gpiod_chip_get_line(chip, 201);
  LED3 = gpiod_chip_get_line(chip, 1);
  LED4 = gpiod_chip_get_line(chip, 6);
  int i = 0;
  gpiod_line_request_output(LED1, "SV", 0);
  gpiod_line_request_output(LED2, "SV", 0);
  gpiod_line_request_output(LED3, "SV", 0);
  gpiod_line_request_output(LED4, "SV", 0);
  while (1) {
    if (i == 0) {
      gpiod_line_set_value(LED1, 1);
      usleep(250000);
      gpiod_line_set_value(LED1, 0);
      usleep(250000);
      i++;
    } else if (i == 1) {
      gpiod_line_set_value(LED2, 1);
      usleep(250000);
      gpiod_line_set_value(LED2, 0);
      usleep(250000);
      i++;
    } else if (i == 2) {
      gpiod_line_set_value(LED3, 1);
      usleep(250000);
      gpiod_line_set_value(LED3, 0);
      usleep(250000);
      i++;
    } else if (i == 3) {
      gpiod_line_set_value(LED4, 1);
      usleep(250000);
      gpiod_line_set_value(LED4, 0);
      usleep(250000);
      i = 0;
    }
  }
}
