#include "s21_test.h"

START_TEST(test_1) { ck_assert_int_eq(s21_abs(9), abs(9)); }
END_TEST

START_TEST(test_2) { ck_assert_int_eq(s21_abs(-9), abs(-9)); }
END_TEST

START_TEST(test_3) { ck_assert_int_eq(s21_abs(-1024), abs(-1024)); }
END_TEST

START_TEST(test_4) { ck_assert_int_eq(s21_abs(302457657), abs(302457657)); }
END_TEST

START_TEST(test_5) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

START_TEST(test_6) { ck_assert_int_eq(s21_abs(-302457657), abs(-302457657)); }
END_TEST

START_TEST(test_7) { ck_assert_int_eq(s21_abs(1), abs(1)); }
END_TEST

START_TEST(test_8) { ck_assert_int_eq(s21_abs(-1), abs(-1)); }
END_TEST

START_TEST(test_9) {
  for (int i = -100000; i < 100000; i += 123)
    ck_assert_double_eq(s21_abs(i), abs(i));
}
END_TEST

Suite *suite_s21_abs(void) {
  Suite *s = suite_create("\033[45m-=S21_ABS=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

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
