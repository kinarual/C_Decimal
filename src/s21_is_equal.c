#include "s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int flag = 1;
  s21_big_decimal value1 = s21_enlarge_D(value_1);
  s21_big_decimal value2 = s21_enlarge_D(value_2);
  flag = s21_is_big_equal(value1, value2);
  return flag;
}