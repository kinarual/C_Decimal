#include "s21_dec_tests.h"

//-----------Операторы сравнения-----------//

// десятичные числа в диапазоне от положительных
//  79,228,162,514,264,337,593,543,950,335 до отрицательных

// коды ошибок:
//  0 - FALSE
//  1 - TRUE

// is_less
START_TEST(s21_less_test_1) {  // 2  3
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(value_1, value_2), 1);
}
END_TEST

START_TEST(positive_zero_and_positive_zero) {
  s21_decimal first = S21_DECIMAL_NULL;
  s21_decimal second = S21_DECIMAL_NULL;

  int res = s21_is_less(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(positive_zero_and_negative_zero) {
  s21_decimal first = S21_DECIMAL_NULL;
  s21_decimal second = S21_DECIMAL_NULL;
  s21_set_sign(&first, 1);

  int res = s21_is_less(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(first_less_then_second) {
  s21_decimal first = {.bits = {35, 34, 0, 0}};
  s21_decimal second = {.bits = {0, 35, 0, 0}};

  int res = s21_is_less(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(second_less_then_first) {
  s21_decimal first = {.bits = {0, 0, 1, 0}};
  s21_decimal second = {.bits = {1231, 748, 0, 0}};

  int res = s21_is_less(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(first_less_negative_sign) {
  s21_decimal first = {.bits = {0, 0, 1, 0x80000000}};
  s21_decimal second = {.bits = {0, 0, 1, 0}};

  int res = s21_is_less(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(equal) {
  s21_decimal first = {.bits = {60, 56, 134, 0x80000000}};
  s21_decimal second = {.bits = {60, 56, 134, 0x80000000}};

  int res = s21_is_less(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(same_value_different_scale_first_less) {
  s21_decimal first = {.bits = {60, 56, 134, 0x80000}};
  s21_decimal second = {.bits = {60, 56, 134, 0x8000}};

  int res = s21_is_less(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(same_all_first_less) {
  s21_decimal first = {.bits = {123, 9, 132, 0x80000}};
  s21_decimal second = {.bits = {12, 52, 154, 0x8000000}};

  int res = s21_is_less(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(same_all_second_less) {
  s21_decimal first = {.bits = {12, 52, 154, 0x8000000}};
  s21_decimal second = {.bits = {123, 9, 132, 0x80000}};

  int res = s21_is_less(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

// is_less_or_equal
START_TEST(positive_zero_and_positive_zero_le) {
  s21_decimal first = S21_DECIMAL_NULL;
  s21_decimal second = S21_DECIMAL_NULL;

  int res = s21_is_less_or_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(positive_zero_and_negative_zero_le) {
  s21_decimal first = S21_DECIMAL_NULL;
  s21_decimal second = S21_DECIMAL_NULL;
  s21_set_sign(&first, 1);

  int res = s21_is_less_or_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(first_less_then_second_le) {
  s21_decimal first = {.bits = {35, 34, 0, 0}};
  s21_decimal second = {.bits = {0, 35, 0, 0}};

  int res = s21_is_less_or_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(second_less_then_first_le) {
  s21_decimal first = {.bits = {0, 0, 1, 0}};
  s21_decimal second = {.bits = {1231, 748, 0, 0}};

  int res = s21_is_less_or_equal(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(first_less_negative_sign_le) {
  s21_decimal first = {.bits = {0, 0, 1, 0x80000000}};
  s21_decimal second = {.bits = {0, 0, 1, 0}};

  int res = s21_is_less_or_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(equal_le) {
  s21_decimal first = {.bits = {60, 56, 134, 0x80000000}};
  s21_decimal second = {.bits = {60, 56, 134, 0x80000000}};

  int res = s21_is_less_or_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(same_value_different_scale_first_less_le) {
  s21_decimal first = {.bits = {60, 56, 134, 0x80000}};
  s21_decimal second = {.bits = {60, 56, 134, 0x1000}};

  int res = s21_is_less_or_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(same_all_first_less_le) {
  s21_decimal first = {.bits = {123, 9, 132, 0x80000}};
  s21_decimal second = {.bits = {12, 52, 154, 0x8000000}};

  int res = s21_is_less_or_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(same_all_second_less_le) {
  s21_decimal first = {.bits = {12, 52, 154, 0x8000000}};
  s21_decimal second = {.bits = {123, 9, 132, 0x80000}};

  int res = s21_is_less_or_equal(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

// is_greater

START_TEST(positive_zero_and_negative_zero_gr) {
  s21_decimal first = S21_DECIMAL_NULL;
  s21_decimal second = S21_DECIMAL_NULL;
  s21_set_sign(&second, 1);
  int res = s21_is_greater(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(first_greater_then_second_gr) {
  s21_decimal first = {{0, 0, 1, 0}};
  s21_decimal second = {{98761, 12312, 0, 0}};

  int res = s21_is_greater(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(first_less_then_second_gr) {
  s21_decimal first = {{98761, 12312, 0, 0}};
  s21_decimal second = {{0, 0, 1, 0}};

  int res = s21_is_greater(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(value_equal_first_positive_second_negative_gr) {
  s21_decimal first = {.bits = {98761, 123, 1, 0}};
  s21_decimal second = {.bits = {98761, 123, 1, 0x80000000}};

  int res = s21_is_greater(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(first_value_less_first_scale_less_first_greater_gr) {
  s21_decimal first = {{35, 1123, 0, 0x1000}};
  s21_decimal second = {{98761, 123, 1, 0x80000}};

  int res = s21_is_greater(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(first_value_less_first_negative_gr) {
  s21_decimal first = {{35, 1123, 0, 0x1000}};
  s21_decimal second = {{98761, 123, 1, 0x80000}};
  s21_set_sign(&first, 1);

  int res = s21_is_greater(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(first_value_less_first_negative_second_negative_gr) {
  s21_decimal first = {{35, 1123, 0, 0x80000}};
  s21_decimal second = {{98761, 123, 1, 0x1000}};

  s21_set_sign(&first, 1);
  s21_set_sign(&second, 1);

  int res = s21_is_greater(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

// is_greater_or_equal

START_TEST(positive_zero_and_negative_zero_ge) {
  s21_decimal first = S21_DECIMAL_NULL;
  s21_decimal second = S21_DECIMAL_NULL;

  s21_set_sign(&second, 1);

  int res = s21_is_greater_or_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(first_greater_then_second_ge) {
  s21_decimal first = {{0, 0, 1, 0}};
  s21_decimal second = {{98761, 12312, 0, 0}};

  int res = s21_is_greater_or_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(first_less_then_second_ge) {
  s21_decimal first = {{98761, 12312, 0, 0}};
  s21_decimal second = {{0, 0, 1, 0}};

  int res = s21_is_greater_or_equal(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(value_equal_first_positive_second_negative_ge) {
  s21_decimal first = {{98761, 123, 1, 0}};
  s21_decimal second = {{98761, 123, 1, 0x80000000}};

  int res = s21_is_greater_or_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(first_value_less_first_scale_less_first_greater_ge) {
  s21_decimal first = {{35, 1123, 0, 0x1000}};
  s21_decimal second = {{98761, 123, 1, 0x80000}};

  int res = s21_is_greater_or_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(first_value_less_first_negative_ge) {
  s21_decimal first = {{35, 1123, 0, 0x1000}};
  s21_decimal second = {{98761, 123, 1, 0x80000}};
  s21_set_sign(&first, 1);

  int res = s21_is_greater_or_equal(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(first_value_less_first_negative_second_negative_ge) {
  s21_decimal first = {{35, 1123, 0, 0x80000}};
  s21_decimal second = {{98761, 123, 1, 0x1000}};

  s21_set_sign(&first, 1);
  s21_set_sign(&second, 1);

  int res = s21_is_greater_or_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

// is_equal

START_TEST(positive_zero_equal_other_positive_zero_e) {
  s21_decimal first = S21_DECIMAL_NULL;
  s21_decimal second = S21_DECIMAL_NULL;

  int res = s21_is_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(negative_zero_equal_other_negative_zero_e) {
  s21_decimal first = S21_DECIMAL_NULL;
  s21_decimal second = S21_DECIMAL_NULL;
  s21_set_sign(&first, 1);
  s21_set_sign(&second, 1);

  int res = s21_is_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(positive_zero_equal_negative_zero_e) {
  s21_decimal first = S21_DECIMAL_NULL;
  s21_decimal second = S21_DECIMAL_NULL;
  s21_set_sign(&second, 1);  // Set second as negative zero

  int res = s21_is_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(same_value_decimals_is_equal_e) {
  s21_decimal first = {{0, 2, 4, 34}};
  s21_decimal second = {{0, 2, 4, 34}};

  int res = s21_is_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(same_values_with_different_sign_is_not_equal_e) {
  s21_decimal first = {{0, 2, 4, 34}};
  s21_decimal second = {{0, 2, 4, 34}};
  s21_set_sign(&second, 1);

  int res = s21_is_equal(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(same_values_different_scale_is_equal_e) {
  s21_decimal first = {{0, 0xffffffff, 0, 0}};
  s21_decimal second = {{0, 0xfffe7960, 0x1869f, 0x50000}};  // scale 5

  int res = s21_is_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

// is_not_equal

START_TEST(positive_zero_and_negative_zero_ne) {
  s21_decimal first = S21_DECIMAL_NULL;
  s21_decimal second = S21_DECIMAL_NULL;
  s21_set_sign(&second, 1);

  int res = s21_is_not_equal(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(positive_zero_and_positive_zero_ne) {
  s21_decimal first = S21_DECIMAL_NULL;
  s21_decimal second = S21_DECIMAL_NULL;

  int res = s21_is_not_equal(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(negative_zero_and_negative_zero_ne) {
  s21_decimal first = S21_DECIMAL_NULL;
  s21_decimal second = S21_DECIMAL_NULL;
  s21_set_sign(&first, 1);
  s21_set_sign(&second, 1);

  int res = s21_is_not_equal(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(same_value_decimals_ne) {
  s21_decimal first = {{0, 2, 4, 34}};
  s21_decimal second = {{0, 2, 4, 34}};

  int res = s21_is_not_equal(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

START_TEST(same_values_with_different_sign_is_not_equal_ne) {
  s21_decimal first = {{0, 2, 4, 34}};
  s21_decimal second = {{0, 2, 4, 34}};
  s21_set_sign(&second, 1);

  int res = s21_is_not_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(different_values_ne) {
  s21_decimal first = {{0, 2, 4, 34}};
  s21_decimal second = {{0, 2, 25, 34}};

  int res = s21_is_not_equal(first, second);

  ck_assert_int_eq(res, S21_TRUE);
}
END_TEST

START_TEST(same_values_different_scale_is_equal_ne) {
  s21_decimal first = {{0, 0xffffffff, 0, 0}};
  s21_decimal second = {{0, 0xfffe7960, 0x1869f, 0x50000}};  // scale 5

  int res = s21_is_not_equal(first, second);

  ck_assert_int_eq(res, S21_FALSE);
}
END_TEST

void srunner_add_compare_tests(SRunner *sr) {
  Suite *save_v3 = suite_create("Compare");
  TCase *tc_compare = tcase_create("Compare");
  suite_add_tcase(save_v3, tc_compare);

  // is_less
  tcase_add_test(tc_compare, s21_less_test_1);
  tcase_add_test(tc_compare, positive_zero_and_positive_zero);
  tcase_add_test(tc_compare, positive_zero_and_negative_zero);
  tcase_add_test(tc_compare, first_less_then_second);
  tcase_add_test(tc_compare, second_less_then_first);
  tcase_add_test(tc_compare, first_less_negative_sign);
  tcase_add_test(tc_compare, equal);
  tcase_add_test(tc_compare, same_value_different_scale_first_less);
  tcase_add_test(tc_compare, same_all_first_less);
  tcase_add_test(tc_compare, same_all_second_less);

  // is_less_or_equal
  tcase_add_test(tc_compare, positive_zero_and_positive_zero_le);
  tcase_add_test(tc_compare, positive_zero_and_negative_zero_le);
  tcase_add_test(tc_compare, first_less_then_second_le);
  tcase_add_test(tc_compare, second_less_then_first_le);
  tcase_add_test(tc_compare, first_less_negative_sign_le);
  tcase_add_test(tc_compare, equal_le);
  tcase_add_test(tc_compare, same_value_different_scale_first_less_le);
  tcase_add_test(tc_compare, same_all_first_less_le);
  tcase_add_test(tc_compare, same_all_second_less_le);
  // is_greater
  tcase_add_test(tc_compare, positive_zero_and_negative_zero_gr);
  tcase_add_test(tc_compare, first_greater_then_second_gr);
  tcase_add_test(tc_compare, first_less_then_second_gr);
  tcase_add_test(tc_compare, value_equal_first_positive_second_negative_gr);
  tcase_add_test(tc_compare,
                 first_value_less_first_scale_less_first_greater_gr);
  tcase_add_test(tc_compare, first_value_less_first_negative_gr);
  tcase_add_test(tc_compare,
                 first_value_less_first_negative_second_negative_gr);
  // is_greater_or_equal

  tcase_add_test(tc_compare, positive_zero_and_negative_zero_ge);
  tcase_add_test(tc_compare, first_greater_then_second_ge);
  tcase_add_test(tc_compare, first_less_then_second_ge);
  tcase_add_test(tc_compare, value_equal_first_positive_second_negative_ge);
  tcase_add_test(tc_compare,
                 first_value_less_first_scale_less_first_greater_ge);
  tcase_add_test(tc_compare, first_value_less_first_negative_ge);
  tcase_add_test(tc_compare,
                 first_value_less_first_negative_second_negative_ge);

  // is_equal
  tcase_add_test(tc_compare, positive_zero_equal_other_positive_zero_e);
  tcase_add_test(tc_compare, negative_zero_equal_other_negative_zero_e);
  tcase_add_test(tc_compare, positive_zero_equal_negative_zero_e);
  tcase_add_test(tc_compare, same_value_decimals_is_equal_e);
  tcase_add_test(tc_compare, same_values_with_different_sign_is_not_equal_e);
  tcase_add_test(tc_compare, same_values_different_scale_is_equal_e);

  // is_not_equal
  tcase_add_test(tc_compare, positive_zero_and_negative_zero_ne);
  tcase_add_test(tc_compare, positive_zero_and_positive_zero_ne);
  tcase_add_test(tc_compare, negative_zero_and_negative_zero_ne);
  tcase_add_test(tc_compare, same_value_decimals_ne);
  tcase_add_test(tc_compare, same_values_with_different_sign_is_not_equal_ne);
  tcase_add_test(tc_compare, different_values_ne);
  tcase_add_test(tc_compare, same_values_different_scale_is_equal_ne);

  srunner_add_suite(sr, save_v3);
}