#include "s21_test.h"

START_TEST(test_1) {
  for (double i = -546456.5434654; i < 543456.5654345; i += 10.2345)
    ck_assert_ldouble_eq(s21_fabs(i), fabs(i));
}
END_TEST

START_TEST(test_2) { ck_assert_ldouble_eq(s21_fabs(0.0), fabs(0.0)); }
END_TEST

START_TEST(test_3) { ck_assert_ldouble_eq(s21_fabs(-0.0), fabs(-0.0)); }
END_TEST

START_TEST(test_4) { ck_assert_ldouble_eq(s21_fabs(S21_INF), fabs(S21_INF)); }
END_TEST

START_TEST(test_5) {
  ck_assert_ldouble_eq(s21_fabs(S21_INF_NEGATIV), fabs(S21_INF_NEGATIV));
}
END_TEST

Suite *suite_s21_fabs(void) {
  Suite *s = suite_create("\033[45m-=S21_FABS=-\033[0m");
  TCase *tc = tcase_create("fabs_tc");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);

  suite_add_tcase(s, tc);
  return s;
}