#include "s21_test.h"

START_TEST(test_1) { ck_assert_double_eq(s21_exp(9.0), exp(9.0)); }
END_TEST

START_TEST(test_2) {
  ck_assert_double_eq_tol(s21_exp(-9.123), exp(-9.123), 0.0000001);
}
END_TEST

START_TEST(test_3) { ck_assert_double_eq(s21_exp(-1024.101), exp(-1024.101)); }
END_TEST

START_TEST(test_4) { ck_assert_double_eq(s21_exp(302457657), exp(302457657)); }
END_TEST

START_TEST(test_5) { ck_assert_double_eq(s21_exp(0.0), exp(0.0)); }
END_TEST

START_TEST(test_6) {
  ck_assert_double_eq(s21_exp(-302457657), exp(-302457657));
}
END_TEST

START_TEST(test_7) { ck_assert_double_eq(s21_exp(1357.389), exp(1357.389)); }
END_TEST

START_TEST(test_8) { ck_assert_double_eq(s21_exp(-1357.389), exp(-1357.389)); }
END_TEST

START_TEST(test_9) { ck_assert_double_eq(s21_exp(555), exp(555)); }
END_TEST

START_TEST(test_10) {
  for (double i = -99.13579; i < 99.13579; i += 11.789239)
    ck_assert_double_eq(s21_exp(i), exp(i));
}
END_TEST

Suite *suite_s21_exp(void) {
  Suite *s = suite_create("\033[45m-=S21_EXP=-\033[0m");
  TCase *tc = tcase_create("exp_tc");

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
