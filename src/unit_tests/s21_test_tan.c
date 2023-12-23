#include "s21_test.h"

START_TEST(test_1) {
  for (long double i = -19520.0; i < 19520.0; i += 22.4896)
    ck_assert_double_eq_tol(s21_tan(i), tan(i), 0.000001);
}

START_TEST(test_2) { ck_assert_double_eq(s21_tan(0), tan(0)); }
END_TEST

START_TEST(test_3) { ck_assert_double_eq(s21_tan(-0), tan(-0)); }
END_TEST

START_TEST(test_4) {
  ck_assert_double_eq_tol(s21_tan(10e-07), tan(10e-07), 0.0000001);
}
END_TEST

START_TEST(test_5) {
  ck_assert_double_eq_tol(s21_tan(10e+06), tan(10e+06), 0.0000001);
}
END_TEST

START_TEST(test_6) { ck_assert_double_nan(s21_tan(S21_INF)); }
END_TEST

START_TEST(test_7) { ck_assert_double_nan(s21_tan(S21_INF_NEGATIV)); }
END_TEST

START_TEST(test_8) { ck_assert_double_nan(s21_tan(S21_NAN)); }
END_TEST

Suite *suite_s21_tan(void) {
  Suite *s = suite_create("\033[45m-=S21_TAN=-\033[0m");
  TCase *tc = tcase_create("tan_tc");

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
