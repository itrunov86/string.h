#include "s21_test.h"

START_TEST(test_1) {
  for (long double i = -1000000.0; i < 1000000; i += 12.123456)
    ck_assert_double_eq_tol(s21_sin(i), sin(i), 0.000001);
}
END_TEST

START_TEST(test_2) { ck_assert_double_eq(s21_sin(-0.0), sin(-0.0)); }
END_TEST

START_TEST(test_3) { ck_assert_double_eq(s21_sin(0.0), sin(0.0)); }
END_TEST

START_TEST(test_4) { ck_assert_double_eq(s21_sin(-1.0), sin(-1.0)); }
END_TEST

START_TEST(test_5) { ck_assert_double_eq(s21_sin(1.0), sin(1.0)); }
END_TEST

START_TEST(test_6) { ck_assert_double_nan(s21_sin(S21_INF)); }
END_TEST

START_TEST(test_7) { ck_assert_double_nan(s21_sin(S21_INF_NEGATIV)); }
END_TEST

START_TEST(test_8) { ck_assert_double_nan(s21_sin(S21_NAN)); }
END_TEST

START_TEST(test_9) {
  double x = S21_PI - 0.001;
  ck_assert_double_eq_tol(s21_sin(x), sin(x), 1e-6);
}
END_TEST

START_TEST(test_10) {
  double x = S21_PI - 1;
  ck_assert_double_eq_tol(s21_sin(x), sin(x), 1e-6);
}
END_TEST

Suite *suite_s21_sin(void) {
  Suite *s = suite_create("\033[45m-=S21_SIN=-\033[0m");
  TCase *tc = tcase_create("sin_tc");

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

  suite_add_tcase(s, tc);
  return s;
}
