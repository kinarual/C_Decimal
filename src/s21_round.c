#include "s21_decimal.h"
#include "stdio.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int scale = s21_get_pow(&value);
  int sign = s21_get_sign(&value);
  s21_decimal konec = {{0, 0, 0, 0}};
  s21_decimal nachalo = {{0, 0, 0, 0}};
  s21_decimal nol_pyat;
  nol_pyat.bits[0] = 0b0000000000000101;
  nol_pyat.bits[1] = 0b0000000000000000;
  nol_pyat.bits[2] = 0b0000000000000000;
  nol_pyat.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal odin = {{1, 0, 0, 0}};
  if (sign) {
    s21_set_bit(&value, 127, 0);
  } else {
    s21_set_bit(&value, 127, 0);
  }
  if (scale > 0) {
    s21_truncate(value, &nachalo);
    s21_sub(value, nachalo, &konec);
    if (s21_is_greater_or_equal(konec, nol_pyat)) {
      s21_add(nachalo, odin, result);
    } else {
      *result = nachalo;
    }
  } else {
    *result = value;
  }
  if (sign) {
    s21_set_sign(result, 1);
  } else {
    s21_set_sign(result, 0);
  }
  return 0;
}