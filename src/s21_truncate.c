#include "s21_decimal.h"
// Возвращает целые цифры указанного Decimal числа;
// любые дробные цифры отбрасываются, включая конечные нули.

int s21_truncate(s21_decimal value, s21_decimal *result) {
  // Зануление резутата
  for (int i = 0; i < 4; i++) {
    result->bits[i] = 0;
  }

  int flag = 0;  // Код ошибки

  s21_big_decimal value1 =
      s21_enlarge_D(value);  // Перевод из decimal в big decimal
  s21_big_decimal result1 = s21_enlarge_D(*result);

  int pow = s21_get_big_pow(&value1);
  if (pow >= 0 && pow <= 28) {  // Если есть степень
    result1 = value1;  // Приравниваем decimal к результату
    int value_pow = s21_get_big_pow(&result1);  // Значение степени
    while (value_pow) {
      s21_div_ten(&result1);
      value_pow--;
    }
    s21_set_big_pow(&result1, 0);  // Зануление степени в результате
    *result = s21_cut_D(result1);  // Перевод из big decimal в decimal

  } else {
    flag = 1;  // Ошибка
  }

  return flag;
}