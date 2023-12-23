#include "s21_test.h"

START_TEST(log_1) { ck_assert_double_eq_tol(s21_log(1), log(1), 0.000001); }
END_TEST

START_TEST(log_0) { ck_assert_double_eq(s21_log(0), log(0)); }
END_TEST

START_TEST(log_12345) {
  ck_assert_double_eq_tol(s21_log(12345), log(12345), 0.000001);
}
END_TEST

START_TEST(log_minus_12345) { ck_assert_double_nan(s21_log(-12345)); }
END_TEST

START_TEST(log_0_98765) {
  ck_assert_double_eq_tol(s21_log(0.98765), log(0.98765), 0.000001);
}
END_TEST

START_TEST(log_7654_2345) {
  ck_assert_double_eq_tol(s21_log(7654.2345), log(7654.2345), 0.000001);
}
END_TEST

START_TEST(log_NAN) {
  ck_assert_double_nan(s21_log(S21_NAN));
  ck_assert_double_nan(log(S21_NAN));
}
END_TEST

START_TEST(log_inf) { ck_assert_double_eq(s21_log(S21_INF), log(S21_INF)); }
END_TEST

START_TEST(log_inf_negativ) {
  ck_assert_double_nan(s21_log(S21_INF_NEGATIV));
  ck_assert_double_nan(log(S21_INF_NEGATIV));
}
END_TEST

START_TEST(log_max) {
  ck_assert_double_eq_tol(s21_log(1.797E20), log(1.797E20), 1e-6);
}
END_TEST

Suite *suite_s21_log(void) {
  Suite *s = suite_create("\033[45m-=S21_LOG=-\033[0m");
  TCase *tc = tcase_create("log_tc");

  tcase_add_test(tc, log_1);
  tcase_add_test(tc, log_0);
  tcase_add_test(tc, log_12345);
  tcase_add_test(tc, log_minus_12345);
  tcase_add_test(tc, log_0_98765);
  tcase_add_test(tc, log_7654_2345);
  tcase_add_test(tc, log_NAN);
  tcase_add_test(tc, log_inf);
  tcase_add_test(tc, log_inf_negativ);
  tcase_add_test(tc, log_max);

  suite_add_tcase(s, tc);
  return s;
}