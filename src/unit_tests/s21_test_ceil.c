#include "s21_test.h"

START_TEST(test_1) { ck_assert_double_eq(s21_ceil(0), ceil(0)); }
END_TEST

START_TEST(test_2) { ck_assert_double_eq(s21_ceil(0.0), ceil(0.0)); }
END_TEST

START_TEST(test_3) { ck_assert_double_eq(s21_ceil(-0.0), ceil(-0.0)); }
END_TEST

START_TEST(test_4) { ck_assert_double_eq(s21_ceil(9.012), ceil(9.012)); }
END_TEST

START_TEST(test_5) { ck_assert_double_eq(s21_ceil(-9.123), ceil(-9.123)); }
END_TEST

START_TEST(test_6) {
  ck_assert_double_eq(s21_ceil(-1024.101), ceil(-1024.101));
}
END_TEST

START_TEST(test_7) { ck_assert_double_eq(s21_ceil(1024.189), ceil(1024.189)); }
END_TEST

START_TEST(test_8) {
  ck_assert_double_eq(s21_ceil(1234567890123456.469),
                      ceil(1234567890123456.469));
}
END_TEST

START_TEST(test_9) {
  ck_assert_double_eq(s21_ceil(-1234567890123456.469),
                      ceil(-1234567890123456.469));
}
END_TEST

START_TEST(test_10) { ck_assert_double_eq(s21_ceil(5.49e+11), ceil(5.49e+11)); }
END_TEST

START_TEST(test_11) { ck_assert_double_eq(s21_ceil(5.49e-11), ceil(5.49e-11)); }
END_TEST

START_TEST(test_12) {
  for (long double i = -100000.13579; i < 100000.13579; i += 10.789239)
    ck_assert_double_eq(s21_ceil(i), ceil(i));
}
END_TEST

START_TEST(test_13) { ck_assert_double_eq(s21_ceil(S21_INF), ceil(S21_INF)); }
END_TEST

START_TEST(test_14) {
  ck_assert_double_eq(s21_ceil(S21_INF_NEGATIV), ceil(S21_INF_NEGATIV));
}
END_TEST

START_TEST(test_15) { ck_assert_double_nan(s21_ceil(S21_NAN)); }
END_TEST

Suite *suite_s21_ceil(void) {
  Suite *s = suite_create("\033[45m-=S21_CEIL=-\033[0m");
  TCase *tc = tcase_create("ceil_tc");

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
  tcase_add_test(tc, test_13);
  tcase_add_test(tc, test_14);
  tcase_add_test(tc, test_15);

  suite_add_tcase(s, tc);
  return s;
}
