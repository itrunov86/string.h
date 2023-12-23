#include "s21_test.h"

START_TEST(test_2) { ck_assert_double_eq(s21_floor(-0.0), floor(-0.0)); }
END_TEST

START_TEST(test_3) {
  ck_assert_double_eq(s21_floor(1024.256), floor(1024.256));
}
END_TEST

START_TEST(test_4) {
  ck_assert_double_eq(s21_floor(-1024.256), floor(-1024.256));
}
END_TEST

START_TEST(test_4_1) { ck_assert_double_eq(s21_floor(-4.856), floor(-4.856)); }
END_TEST

START_TEST(test_5) {
  ck_assert_double_eq(s21_floor(1024.256), floor(1024.256));
}
END_TEST

START_TEST(test_6) { ck_assert_double_eq(s21_floor(1.0), floor(1.0)); }
END_TEST

START_TEST(test_7) { ck_assert_double_eq(s21_floor(0.0), floor(0.0)); }
END_TEST

START_TEST(test_8) { ck_assert_double_eq(s21_floor(5.0), floor(5.0)); }
END_TEST

START_TEST(test_9) { ck_assert_double_eq(s21_floor(-5.0), floor(-5.0)); }
END_TEST

START_TEST(test_10) {
  double x = S21_INF;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(test_11) {
  double x = -S21_INF;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(test_12) { ck_assert_double_eq(s21_floor(S21_INF), floor(S21_INF)); }
END_TEST

START_TEST(test_13) {
  ck_assert_double_eq(s21_floor(S21_INF_NEGATIV), floor(S21_INF_NEGATIV));
}
END_TEST

START_TEST(test_14) { ck_assert_double_nan(s21_floor(S21_NAN)); }
END_TEST

Suite *suite_s21_floor(void) {
  Suite *s = suite_create("\033[45m-=S21_FLOOR=-\033[0m");
  TCase *tc = tcase_create("floor_tc");

  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_4_1);
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

  suite_add_tcase(s, tc);
  return s;
}
