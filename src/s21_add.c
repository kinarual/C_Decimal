#include <stdio.h>

#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_reset_all_bit(result);

  int error = 0;  // Код ошибки

  s21_big_decimal value1 = s21_enlarge_D(value_1);
  s21_big_decimal value2 = s21_enlarge_D(value_2);
  s21_big_decimal result1 = s21_enlarge_D(*result);

  s21_add_big_decimal(value1, value2, &result1);
  // Проверка на переполнение мантиссы

  int check = s21_overflow_2(&result1);
  if (!check) {
    *result = s21_cut_D(result1);
  }
  error = check;  // Присвоение вывод overflow к error переменной

  return error;
}