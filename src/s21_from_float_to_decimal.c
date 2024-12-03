#include <math.h>
#include <stdint.h>

#include "s21_decimal.h"
// Из float в decimal

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  for (int i = 0; i < 4; i++) {
    dst->bits[i] = 0;
  }

  int error_flag = 0;

  if (isinf(src) || isnan(src)) {
    error_flag = 1;
  } else {
    if (src != 0) {
      int sign_bit = *(int *)&src >> 31;
      int exponent = ((*(int *)&src & 0x7F800000) >> 23) - 127;
      double mantissa = (double)fabs(src);

      int offset = 0;  // cмещение (количество умножений на 10)

      // определяем, сколько раз нужно умножить mantissa на 10, чтобы мантисса
      // была >= 1
      while (offset < 28 && (int)mantissa / (1 << 21) == 0) {
        mantissa *= 10;
        offset++;
      }

      // округляем mantissa до целого числа
      mantissa = round(mantissa);

      // проверяем, что результат валиден для формата decimal
      if (offset <= 28 && (exponent >= -94 && exponent <= 95)) {
        float mantissa_as_float = (float)mantissa;

        // убираем нулевые десятичные знаки
        while (fmod(mantissa_as_float, 10) == 0 && offset > 0) {
          offset--;
          mantissa_as_float /= 10;
        }

        // извлекаем экспоненту для мантиссы
        exponent = ((*(int *)&mantissa_as_float & 0x7F800000) >> 23) - 127;

        // устанавливаем бит экспоненты
        s21_set_bit(dst, exponent, 1);

        for (int i = exponent - 1, j = 22; j >= 0; i--, j--) {
          // устанавливаем биты мантиссы в dst->bits
          if ((*(int *)&mantissa_as_float >> j) & 1) {
            s21_set_bit(dst, i, 1);
          }
        }

        // устанавливаем знак и смещение в dst->bits[3]
        dst->bits[3] = (sign_bit << 31) | (offset << 16);
      }
    }
  }

  return error_flag;
}