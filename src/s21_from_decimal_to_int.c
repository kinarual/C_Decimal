#include <math.h>

#include "s21_decimal.h"

// Из decimal в int

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;
  int sign = s21_get_bit(&src, 127);
  int scale = s21_get_pow(&src);
  if ((scale) > 0) {
    s21_truncate(src, &src);
  }
  if (src.bits[0] > 2147483647) {
    error = 1;
  } else {
    *dst = src.bits[0];
    if (sign) {
      *dst *= -1;
    }
  }
  if (src.bits[1] || src.bits[2]) {
    error = 1;
  }
  return error;
}