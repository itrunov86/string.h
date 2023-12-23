#include "s21_test.h"

START_TEST(test_1) {
  for (long double i = -1; i < 1; i += 0.01)
    ck_assert_double_eq_tol(s21_asin(i), asin(i), 0.0000001);
  /*   ck_assert_double_eq_tol(s21_asin(num), asin(num), 1e-6); */
}
END_TEST

START_TEST(test_2) {
  double num = 1;
  ck_assert_double_eq_tol(s21_asin(num), asin(num), 1e-6);
}
END_TEST

START_TEST(test_3) {
  double num = 0;
  ck_assert_double_eq_tol(s21_asin(num), asin(num), 1e-6);
}
END_TEST

START_TEST(test_4) {
  double num = 12.21;
  ck_assert_double_nan(s21_asin(num));
}
END_TEST

START_TEST(test_5) {
  double num = -12.21;
  ck_assert_double_nan(s21_asin(num));
}
END_TEST

START_TEST(test_6) {
  float num = S21_INF;
  ck_assert_double_nan(s21_asin(num));
}
END_TEST

START_TEST(test_7) {
  float num = S21_INF_NEGATIV;
  ck_assert_double_nan(s21_asin(num));
}
END_TEST

START_TEST(test_8) {
  double num = -0.7546;
  ck_assert_double_eq_tol(s21_asin(num), asin(num), 1e-6);
}
END_TEST

START_TEST(test_9) {
  double num = 0.9546;
  ck_assert_double_eq_tol(s21_asin(num), asin(num), 1e-6);
}
END_TEST

START_TEST(test_10) {
  ck_assert_double_nan(s21_asin(S21_NAN));
  ck_assert_double_nan(acos(S21_NAN));
}
END_TEST

START_TEST(test_11) {
  double num = -15.0;
  ck_assert_double_nan(s21_asin(num));
}
END_TEST

START_TEST(test_12) {
  const double num = 15;
  ck_assert_double_nan(s21_asin(num));
}
END_TEST

Suite *suite_s21_asin(void) {
  Suite *s = suite_create("\033[45m-=S21_ASIN=-\033[0m");
  TCase *tc = tcase_create("asin_tc");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  tcase_add_test(tc, test_7);
  tcase_add_test(tc, test_8);
  tcase_add_test(tc, test_9);
  tcase_add_test(tc, test_10);
  tcase_add_test(tc, test_11);
  tcase_add_test(tc, test_12);

  suite_add_tcase(s, tc);
  return s;
}