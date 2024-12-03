#include <math.h>

#include "s21_decimal.h"
// Из decimal в float

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  float rez = 0;
  for (int i = 0; i <= 95; i++) {
    rez = rez + s21_get_bit(&src, i) * pow(2, i);
  }
  rez = rez / pow(10, s21_get_pow(&src));
  if (s21_get_sign(&src)) {
    rez = rez * (-1);
  }
  if ((fabs(*dst) < 1e-28) && (fabs(*dst) > 0)) {
    return 1;
  }
  *dst = rez;
  return 0;
}