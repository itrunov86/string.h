#include "s21_test.h"

START_TEST(test_1) {
  for (long double i = -10000000; i < 10000000; i += 12.123456)
    ck_assert_double_eq_tol(s21_atan(i), atan(i), 0.0000001);
}

START_TEST(test_2) {
  ck_assert_double_eq(s21_atan(S21_INF_NEGATIV), atan(S21_INF_NEGATIV));
}
END_TEST

START_TEST(test_3) {
  ck_assert_double_nan(s21_atan(S21_NAN));
  ck_assert_double_nan(atan(S21_NAN));
}
END_TEST

START_TEST(test_4) { ck_assert_double_eq_tol(s21_atan(-1), atan(-1), 1e-6); }
END_TEST

START_TEST(test_5) { ck_assert_double_eq_tol(s21_atan(0), atan(0), 1e-6); }
END_TEST

START_TEST(test_6) {
  ck_assert_double_eq_tol(s21_atan(0.75123), atan(0.75123), 1e-6);
}
END_TEST

START_TEST(test_7) {
  ck_assert_double_eq_tol(s21_atan(5.321), atan(5.321), 1e-6);
}
END_TEST

START_TEST(test_8) {
  ck_assert_double_eq_tol(s21_atan(15.321), atan(15.321), 1e-6);
}
END_TEST

START_TEST(test_9) {
  ck_assert_double_eq_tol(s21_atan(-15.321), atan(-15.321), 1e-6);
}
END_TEST

Suite *suite_s21_atan(void) {
  Suite *s = suite_create("\033[45m-=S21_ATAN=-\033[0m");
  TCase *tc = tcase_create("atan_tc");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  tcase_add_test(tc, test_7);
  tcase_add_test(tc, test_8);
  tcase_add_test(tc, test_9);

  suite_add_tcase(s, tc);
  return s;
}