#include "s21_dec_tests.h"

//-----------Арифметика-----------//

// десятичные числа в диапазоне от положительных
//  79,228,162,514,264,337,593,543,950,335 до отрицательных

// коды ошибок:
//  0 - OK
//  1 - число слишком велико или равно бесконечности
//  2 - число слишком мало или равно отрицательной бесконечности
//  3 - деление на 0

// add function
START_TEST(s21_add_test_1) {  // 2 + 3 = 5
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{5, 0, 0, 0}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_2) {  // -2 + 3 = 1
  s21_decimal value_1 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{1, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_3) {  // 2 + (-3) = -1
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{1, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_4) {  // -2 + (-3) = -5
  s21_decimal value_1 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{5, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_5) {  // -5 + 3 = -2
  s21_decimal value_1 = {{5, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{2, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_6) {  // 5 + (-3) = 2
  s21_decimal value_1 = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{2, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_7) {  // 3.33 + 3.3 = 6.63
  s21_decimal value_1 = {{333, 0, 0, 0b0000000000000000000000000000000}};
  s21_set_pow(&value_1, 2);
  s21_decimal value_2 = {{33, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&value_2, 1);
  s21_decimal result = {0};
  s21_decimal check = {{663, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&check, 2);
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_8) {  // 1.78 + 12.80 = 6.63
  s21_decimal value_1 = {{178, 0, 0, 0b0000000000000000000000000000000}};
  s21_set_pow(&value_1, 2);
  s21_decimal value_2 = {{1280, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&value_2, 2);
  s21_decimal result = {0};
  s21_decimal check = {{1458, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&check, 2);
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_9) {  // 0.12 + 123 = 123.12
  s21_decimal value_1 = {{12, 0, 0, 0b0000000000000000000000000000000}};
  s21_set_pow(&value_1, 2);
  s21_decimal value_2 = {{123, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{12312, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&check, 2);
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_10) {  // -0.017 + 0.0004 = -0.0166
  s21_decimal value_1 = {{17, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_pow(&value_1, 3);
  s21_decimal value_2 = {{4, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&value_2, 4);
  s21_decimal result = {0};
  s21_decimal check = {{166, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_pow(&check, 4);
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_11) {  // 0.000001 + (-0.000001) = 0.000000
  s21_decimal value_1 = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&value_1, 6);
  s21_decimal value_2 = {{1, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_pow(&value_2, 6);
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&check, 6);
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_12) {  // 2 + (-2) = 0
  s21_decimal value_1 = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal value_2 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_13) {  // -2 + 2 = 0
  s21_decimal value_1 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_14) {  // -0.000001 + 0.000001 = 0.000000
  s21_decimal value_1 = {{1, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_pow(&value_1, 6);
  s21_decimal value_2 = {{1, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&value_2, 6);
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&check, 6);
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_15) {  // 0.4444444444444444444444443354 + 10
                               // = 10.444444444444444444444444335

  // 0b1010100010111101001101011011001101000100100010000110000111000001111111100011100011100001011011010
  // = 104444444444444444444444443354

  s21_decimal value_1 = {{0x5c71c2da, 0x1b9eabb9, 0xe5c5bb8, 0x1c0000}};
  s21_decimal value_2 = {{0xa, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{0xcc71c6af, 0xda81ad26, 0x21bf7123, 0x1b0000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_16) {  // 0.00000000000000004294967294 + 10
                               // = 10.00000000000000004294967294
  s21_decimal value_1 = {{0xfffffffe, 0, 0, 0x1a0000}};
  s21_decimal value_2 = {{0xa, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{0xe7fffffe, 0x9fd0803d, 0x33b2e3c, 0x1a0000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(
    s21_add_test_17) {  // 79228162514264337593543950335 + 5 = overflow !!!
  s21_decimal value_1 = {
      {4294967295, 4294967295, 4294967295, 0b00000000000000000000000000000000}};
  s21_set_pow(&value_1, 0);
  s21_decimal value_2 = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&value_2, 0);
  s21_decimal result = {0};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 1);
}
END_TEST

START_TEST(s21_add_test_18) {  // 0.49999 + 0.00001 = 0.50000
  s21_decimal value_1 = {{0x7a11f, 0, 0, 0x60000}};
  s21_decimal value_2 = {{0x1, 0, 0, 0x60000}};
  s21_decimal result = {0};
  s21_decimal check = {{0x7a120, 0, 0, 0x60000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_19) {  // -46551.2345 + 1452.1212
  s21_decimal value_1 = {{465512345, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_pow(&value_1, 4);
  s21_decimal value_2 = {{14521212, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&value_2, 4);
  s21_decimal result = {0};
  s21_decimal check = {{450991133, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_pow(&check, 4);
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_20) {
  s21_decimal value_1 = {{24, 1, 1, -2147418112}};
  s21_decimal value_2 = {{1, 15, 1, 655360}};
  s21_decimal result = {0};
  s21_decimal check = {{0x9682efff, 0x3b9ac9f6, 0x3b9ac9ff, 0x800a0000}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

// sub function
START_TEST(s21_sub_test_1) {  // 2 - 3 = -1
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{1, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_2) {  // -2 - 3 = -5
  s21_decimal value_1 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{5, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_3) {  // 2 - (-3) = 5
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{5, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_4) {  // -2 - (-3) = 1
  s21_decimal value_1 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{1, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_5) {  // -5 - 3 = -8
  s21_decimal value_1 = {{5, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{8, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_6) {  // 5 - (-3) = 8
  s21_decimal value_1 = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{8, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_7) {  // 3.33 - 3.3 = 0.03
  s21_decimal value_1 = {{333, 0, 0, 0b0000000000000000000000000000000}};
  s21_set_pow(&value_1, 2);
  s21_decimal value_2 = {{33, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&value_2, 1);
  s21_decimal result = {0};
  s21_decimal check = {{3, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&check, 2);
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_8) {  // 1.78 - 12.80 = -11.02
  s21_decimal value_1 = {{178, 0, 0, 0b0000000000000000000000000000000}};
  s21_set_pow(&value_1, 2);
  s21_decimal value_2 = {{1280, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&value_2, 2);
  s21_decimal result = {0};
  s21_decimal check = {{1102, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_pow(&check, 2);
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_9) {  // 0.12 - 123 = -122.88
  s21_decimal value_1 = {{12, 0, 0, 0b0000000000000000000000000000000}};
  s21_set_pow(&value_1, 2);
  s21_decimal value_2 = {{123, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{12288, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_pow(&check, 2);
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_10) {  // -0.017 - 0.0004 = -0.0174
  s21_decimal value_1 = {{17, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_pow(&value_1, 3);
  s21_decimal value_2 = {{4, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&value_2, 4);
  s21_decimal result = {0};
  s21_decimal check = {{174, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_pow(&check, 4);
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_11) {  // -0.000001 - (-0.000001) = 0.000000
  s21_decimal value_1 = {{1, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_pow(&value_1, 6);
  s21_decimal value_2 = {{1, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_pow(&value_2, 6);
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&check, 6);
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_12) {  // -2 - (-2) = 0
  s21_decimal value_1 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_13) {  // 2 - 2 = 0
  s21_decimal value_1 = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal value_2 = {{2, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_14) {  // -12133.512 - 11321.21103 = -23454.72303
  s21_decimal value_1 = {{12133512, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_pow(&value_1, 3);
  s21_decimal value_2 = {
      {1132121103, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&value_2, 5);
  s21_decimal result = {0};
  s21_decimal check = {{2345472303, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_pow(&check, 5);
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_sub_test_15) {  // -79228162514264337593543950335 - 1 = OVERFLOW
  s21_decimal value_1 = {
      {4294967295, 4294967295, 4294967295, 0b10000000000000000000000000000000}};
  s21_set_pow(&value_1, 0);
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_set_pow(&value_2, 0);
  s21_decimal result = {0};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 2);
}
END_TEST

// mul function
START_TEST(s21_mul_test_1) {  // 2 * 3 = 6
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{6, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_mul(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_mul_test_2) {  // -2 * 3 = -6
  s21_decimal value_1 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{6, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_mul(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_mul_test_3) {  // 2 * (-3) = -6
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{6, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_mul(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_mul_test_4) {  // -2 * (-3) = 6
  s21_decimal value_1 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{6, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_mul(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_mul_test_5) {  // -5 * 3 = -15
  s21_decimal value_1 = {{5, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{15, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_mul(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_mul_test_6) {  // 5 * (-3) = -15
  s21_decimal value_1 = {{5, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{15, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_mul(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_mul_test_7) {  // 3.33 * 3.3 = 10.989
  s21_decimal value_1 = {{333, 0, 0, 0b0000000000000000000000000000000}};
  s21_set_pow(&value_1, 2);
  s21_decimal value_2 = {{33, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&value_2, 1);
  s21_decimal result = {0};
  s21_decimal check = {{10989, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&check, 3);
  ck_assert_int_eq((s21_mul(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_mul_test_8) {  // 1.78 * 12.80 = 22.7840
  s21_decimal value_1 = {{178, 0, 0, 0b0000000000000000000000000000000}};
  s21_set_pow(&value_1, 2);
  s21_decimal value_2 = {{1280, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&value_2, 2);
  s21_decimal result = {0};
  s21_decimal check = {{227840, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&check, 4);
  ck_assert_int_eq((s21_mul(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_mul_test_9) {  // 0.12 * 123 = 14.76
  s21_decimal value_1 = {{12, 0, 0, 0b0000000000000000000000000000000}};
  s21_set_pow(&value_1, 2);
  s21_decimal value_2 = {{123, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{1476, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&check, 2);
  ck_assert_int_eq((s21_mul(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_mul_test_10) {  // -0.017 * 0.0004 = -0.0000068
  s21_decimal value_1 = {{17, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_pow(&value_1, 3);
  s21_decimal value_2 = {{4, 0, 0, 0b00000000000000000000000000000000}};
  s21_set_pow(&value_2, 4);
  s21_decimal result = {0};
  s21_decimal check = {{68, 0, 0, 0b10000000000000000000000000000000}};
  s21_set_pow(&check, 7);
  ck_assert_int_eq((s21_mul(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(
    s21_mul_test_11) {  // 79228162514264337593543950335 * 2 = OVERFLOW +inf
  s21_decimal value_1 = {
      {4294967295, 4294967295, 4294967295, 0b00000000000000000000000000000000}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal result = {0};
  ck_assert_int_eq((s21_mul(value_1, value_2, &result)), 1);
}
END_TEST

START_TEST(
    s21_mul_test_12) {  // 79228162514264337593543950335 * -2 = OVERFLOW -inf
  s21_decimal value_1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  ck_assert_int_eq((s21_mul(value_1, value_2, &result)), 2);
}
END_TEST

// del function
START_TEST(s21_div_test_1) {  // 6 : 3 = 2
  s21_decimal value_1 = {{6, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{2, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_div(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_div_test_2) {  // -6 : 3 = -2
  s21_decimal value_1 = {{6, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{2, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_div(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_div_test_3) {  // 6 : (-3) = -2
  s21_decimal value_1 = {{6, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{2, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_div(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_div_test_4) {  // -6 : (-3) = 2
  s21_decimal value_1 = {{6, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{2, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_div(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_div_test_5) {  // -15 : 3 = -5
  s21_decimal value_1 = {{15, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{5, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_div(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_div_test_6) {  // -15 : (-3) = 5
  s21_decimal value_1 = {{15, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  s21_decimal check = {{5, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_div(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_div_test_7) {  // 79228162514264337593543950335 : 0 = DIV ZERO
  s21_decimal value_1 = {
      {4294967295, 4294967295, 4294967295, 0b00000000000000000000000000000000}};
  s21_decimal value_2 = {{0, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  ck_assert_int_eq((s21_div(value_1, value_2, &result)), 3);
}
END_TEST

START_TEST(
    s21_div_test_8) {  // 79228162514264337593543950335 : -0.0000 = DIV ZERO
  s21_decimal value_1 = {
      {4294967295, 4294967295, 4294967295, 0b00000000000000000000000000000000}};
  s21_decimal value_2 = {{0, 0, 0, 0x80040000}};
  s21_decimal result = {0};
  ck_assert_int_eq((s21_div(value_1, value_2, &result)), 3);
}
END_TEST

void srunner_add_math_tests(SRunner *sr) {
  Suite *save_v1 = suite_create("Math");
  TCase *tc_math = tcase_create("Math");
  suite_add_tcase(save_v1, tc_math);

  // add func
  tcase_add_test(tc_math, s21_add_test_1);
  tcase_add_test(tc_math, s21_add_test_2);
  tcase_add_test(tc_math, s21_add_test_3);
  tcase_add_test(tc_math, s21_add_test_4);
  tcase_add_test(tc_math, s21_add_test_5);
  tcase_add_test(tc_math, s21_add_test_6);
  tcase_add_test(tc_math, s21_add_test_7);
  tcase_add_test(tc_math, s21_add_test_8);
  tcase_add_test(tc_math, s21_add_test_9);
  tcase_add_test(tc_math, s21_add_test_10);
  tcase_add_test(tc_math, s21_add_test_11);
  tcase_add_test(tc_math, s21_add_test_12);
  tcase_add_test(tc_math, s21_add_test_13);
  tcase_add_test(tc_math, s21_add_test_14);
  tcase_add_test(tc_math, s21_add_test_15);
  tcase_add_test(tc_math, s21_add_test_16);
  tcase_add_test(tc_math, s21_add_test_17);
  tcase_add_test(tc_math, s21_add_test_18);
  tcase_add_test(tc_math, s21_add_test_19);
  tcase_add_test(tc_math, s21_add_test_20);

  // sub func
  tcase_add_test(tc_math, s21_sub_test_1);
  tcase_add_test(tc_math, s21_sub_test_2);
  tcase_add_test(tc_math, s21_sub_test_3);
  tcase_add_test(tc_math, s21_sub_test_4);
  tcase_add_test(tc_math, s21_sub_test_5);
  tcase_add_test(tc_math, s21_sub_test_6);
  tcase_add_test(tc_math, s21_sub_test_7);
  tcase_add_test(tc_math, s21_sub_test_8);
  tcase_add_test(tc_math, s21_sub_test_9);
  tcase_add_test(tc_math, s21_sub_test_10);
  tcase_add_test(tc_math, s21_sub_test_11);
  tcase_add_test(tc_math, s21_sub_test_12);
  tcase_add_test(tc_math, s21_sub_test_13);
  tcase_add_test(tc_math, s21_sub_test_14);
  tcase_add_test(tc_math, s21_sub_test_15);

  // mul func
  tcase_add_test(tc_math, s21_mul_test_1);
  tcase_add_test(tc_math, s21_mul_test_2);
  tcase_add_test(tc_math, s21_mul_test_3);
  tcase_add_test(tc_math, s21_mul_test_4);
  tcase_add_test(tc_math, s21_mul_test_5);
  tcase_add_test(tc_math, s21_mul_test_6);
  tcase_add_test(tc_math, s21_mul_test_7);
  tcase_add_test(tc_math, s21_mul_test_8);
  tcase_add_test(tc_math, s21_mul_test_9);
  tcase_add_test(tc_math, s21_mul_test_10);
  tcase_add_test(tc_math, s21_mul_test_11);
  tcase_add_test(tc_math, s21_mul_test_12);

  // del func
  tcase_add_test(tc_math, s21_div_test_1);
  tcase_add_test(tc_math, s21_div_test_2);
  tcase_add_test(tc_math, s21_div_test_3);
  tcase_add_test(tc_math, s21_div_test_4);
  tcase_add_test(tc_math, s21_div_test_5);
  tcase_add_test(tc_math, s21_div_test_6);
  tcase_add_test(tc_math, s21_div_test_7);
  tcase_add_test(tc_math, s21_div_test_8);

  srunner_add_suite(sr, save_v1);
}