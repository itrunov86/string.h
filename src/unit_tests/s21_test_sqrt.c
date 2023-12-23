#include "s21_test.h"

START_TEST(test_1) { ck_assert_float_nan(s21_sqrt(-19.0)); }
END_TEST

START_TEST(test_2) {
  double x = 12.0;
  double y = 12.0;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(y), 1e-6);
}
END_TEST

START_TEST(test_3) {
  ck_assert_ldouble_eq_tol(s21_sqrt(5.61), sqrt(5.61), 1e-6);
}
END_TEST

START_TEST(test_4) {
  ck_assert_ldouble_eq_tol(s21_sqrt(1.2e15), sqrt(1.2e15), 1e-6);
}
END_TEST

START_TEST(test_5) {
  ck_assert_ldouble_eq_tol(s21_sqrt(1.6e-10), sqrt(1.6e-10), 1e-6);
}
END_TEST

START_TEST(test_6) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);  // 0
}
END_TEST

START_TEST(test_7) {
  ck_assert_ldouble_eq_tol(s21_sqrt(-0.0), sqrt(-0.0), 1e-6);
}
END_TEST

START_TEST(test_8) { ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-6); }
END_TEST

Suite *suite_s21_sqrt(void) {
  Suite *s = suite_create("\033[45m-=S21_SQRT=-\033[0m");
  TCase *tc = tcase_create("sqrt_tc");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  tcase_add_test(tc, test_7);
  tcase_add_test(tc, test_8);

  suite_add_tcase(s, tc);
  return s;
}
