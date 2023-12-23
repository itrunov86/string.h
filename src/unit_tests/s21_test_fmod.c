#include "s21_test.h"

START_TEST(test_1) { ck_assert_double_eq(s21_fmod(0.0, 12), fmod(0.0, 12)); }
END_TEST

START_TEST(test_2) { ck_assert_double_eq(s21_fmod(-0.0, 12), fmod(-0.0, 12)); }
END_TEST

START_TEST(test_3) {
  ck_assert_double_eq_tol(s21_fmod(1024.256, 7.85), fmod(1024.256, 7.85),
                          0.0000001);
}
END_TEST

START_TEST(test_4) {
  ck_assert_double_eq_tol(s21_fmod(-1024.256, 7.85), fmod(-1024.256, 7.85),
                          0.0000001);
}
END_TEST

START_TEST(test_5) {
  ck_assert_double_eq(s21_fmod(1024.256, -3.0), fmod(1024.256, -3.0));
}
END_TEST

START_TEST(test_6) {
  ck_assert_double_eq(s21_fmod(1.0, -15.4560), fmod(1.0, -15.4560));
}
END_TEST

START_TEST(test_7) {
  ck_assert_double_eq(s21_fmod(0.0, -5.45), fmod(0.0, -5.45));
}
END_TEST

START_TEST(test_8) {
  ck_assert_double_eq(s21_fmod(5.0, -5.45), fmod(5.0, -5.45));
}
END_TEST

START_TEST(test_9) { ck_assert_float_nan(s21_fmod(5.0, 0)); }
END_TEST

START_TEST(test_10) {
  ck_assert_msg(isnan(s21_fmod(5.0, S21_NAN)), "Value is not Nan");
}
END_TEST

START_TEST(test_11) { ck_assert_float_nan(s21_fmod(5.0, -0)); }
END_TEST

START_TEST(test_12) { ck_assert_double_eq(s21_fmod(5.0, 5.0), fmod(5.0, 5.0)); }
END_TEST

START_TEST(test_13) {
  ck_assert_double_eq(s21_fmod(-5.0, 5.0), fmod(-5.0, 5.0));
}
END_TEST

START_TEST(test_14) { ck_assert_double_nan(s21_fmod(S21_INF, -1024.256)); }
END_TEST

START_TEST(test_15) {
  ck_assert_double_nan(s21_fmod(S21_INF_NEGATIV, 1024.256));
}
END_TEST

START_TEST(test_16) {
  ck_assert_double_eq(s21_fmod(1024.256, S21_INF), fmod(1024.256, S21_INF));
}
END_TEST

START_TEST(test_17) {
  ck_assert_double_eq(s21_fmod(-1024.256, S21_INF_NEGATIV),
                      fmod(-1024.256, S21_INF_NEGATIV));
}
END_TEST

START_TEST(test_18) { ck_assert_double_nan(s21_fmod(S21_NAN, -1024.256)); }
END_TEST

START_TEST(test_19) { ck_assert_double_nan(s21_fmod(S21_INF, S21_INF)); }
END_TEST

START_TEST(test_20) {
  ck_assert_double_nan(s21_fmod(S21_INF, S21_INF_NEGATIV));
}
END_TEST

START_TEST(test_21) {
  ck_assert_double_nan(s21_fmod(S21_INF_NEGATIV, S21_INF_NEGATIV));
}
END_TEST

START_TEST(test_22) {
  ck_assert_double_nan(s21_fmod(S21_INF_NEGATIV, S21_INF));
}
END_TEST

Suite *suite_s21_fmod(void) {
  Suite *s = suite_create("\033[45m-=S21_FMOD=-\033[0m");
  TCase *tc = tcase_create("fmod_tc");

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
  tcase_add_test(tc, test_16);
  tcase_add_test(tc, test_17);
  tcase_add_test(tc, test_18);
  tcase_add_test(tc, test_19);
  tcase_add_test(tc, test_20);
  tcase_add_test(tc, test_21);
  tcase_add_test(tc, test_22);

  suite_add_tcase(s, tc);
  return s;
}
