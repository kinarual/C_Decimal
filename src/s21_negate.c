#include "s21_decimal.h"
// Возвращает результат умножения указанного Decimal на -1.

int s21_negate(s21_decimal value, s21_decimal *result) {
  s21_reset_all_bit(result);

  for (int i = 0; i <= 3; i++) {
    result->bits[i] = value.bits[i];
  }

  if (s21_get_sign(&value)) {
    s21_set_sign(result, 0);
  } else {
    s21_set_sign(result, 1);
  }
  return 0;
}