#include "s21_test.h"

START_TEST(test_1) {
  for (long double i = -10000.0; i < 10000; i += 120.123456)
    ck_assert_double_eq_tol(s21_cos(i), cos(i), 0.0000001);
}
END_TEST

START_TEST(test_2) { ck_assert_double_eq(s21_cos(-0.0), cos(-0.0)); }
END_TEST

START_TEST(test_3) { ck_assert_double_eq(s21_cos(0.0), cos(0.0)); }
END_TEST

START_TEST(test_4) { ck_assert_double_eq(s21_cos(-1.0), cos(-1.0)); }
END_TEST

START_TEST(test_5) { ck_assert_double_eq(s21_cos(1.0), cos(1.0)); }
END_TEST

START_TEST(test_6) { ck_assert_double_nan(s21_cos(S21_INF)); }
END_TEST

START_TEST(test_7) { ck_assert_double_nan(s21_cos(S21_INF_NEGATIV)); }
END_TEST

START_TEST(test_8) { ck_assert_double_nan(s21_cos(S21_NAN)); }
END_TEST

Suite *suite_s21_cos(void) {
  Suite *s = suite_create("\033[45m-=S21_COS=-\033[0m");
  TCase *tc = tcase_create("cos_tc");

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
