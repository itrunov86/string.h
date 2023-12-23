#include "s21_test.h"

START_TEST(test_1) {
  ck_assert_double_eq(s21_pow(S21_INF, S21_INF), pow(S21_INF, S21_INF));
}
END_TEST

START_TEST(test_2) {
  ck_assert_ldouble_eq_tol(s21_pow(-0.0, 12), pow(-0.0, 12), 1e-6);
}
END_TEST

START_TEST(test_3) {
  ck_assert_double_eq_tol(s21_pow(1024.256, 7.85), pow(1024.256, 7.85), 1e15);
}
END_TEST

START_TEST(test_4) {
  ck_assert_float_nan(s21_pow(-1024.256, 7.85));
  ck_assert_float_nan(pow(-1024.256, 7.85));
}
END_TEST

START_TEST(test_5) {
  ck_assert_ldouble_eq_tol(s21_pow(1024.256, -3.0), pow(1024.256, -3.0), 1e-6);
}
END_TEST

START_TEST(test_6) {
  ck_assert_ldouble_eq(s21_pow(1.0, -15.4560), pow(1.0, -15.4560));
}
END_TEST

START_TEST(test_7) { ck_assert_ldouble_eq(s21_pow(-1, 2), pow(-1, 2)); }
END_TEST

START_TEST(test_8) {
  ck_assert_double_eq(s21_pow(S21_INF_NEGATIV, S21_INF_NEGATIV),
                      pow(S21_INF_NEGATIV, S21_INF_NEGATIV));
}
END_TEST

START_TEST(test_9) {
  ck_assert_double_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_double_nan(pow(S21_NAN, S21_NAN));
}
END_TEST

START_TEST(test_10) {
  ck_assert_double_nan(s21_pow(S21_NAN, S21_INF));
  ck_assert_double_nan(pow(S21_NAN, S21_INF));
}
END_TEST

START_TEST(test_11) {
  ck_assert_double_nan(s21_pow(S21_NAN, S21_INF_NEGATIV));
  ck_assert_double_nan(pow(S21_NAN, S21_INF_NEGATIV));
}
END_TEST

START_TEST(test_12) {
  ck_assert_double_nan(s21_pow(S21_INF, S21_NAN));
  ck_assert_double_nan(pow(S21_INF, S21_NAN));
}
END_TEST

START_TEST(test_13) {
  ck_assert_double_eq(s21_pow(S21_INF_NEGATIV, S21_INF),
                      pow(S21_INF_NEGATIV, S21_INF));
}
END_TEST

START_TEST(test_14) {
  ck_assert_double_nan(s21_pow(S21_INF_NEGATIV, S21_NAN));
  ck_assert_double_nan(pow(S21_INF_NEGATIV, S21_NAN));
}
END_TEST

START_TEST(test_15) { ck_assert_ldouble_eq(s21_pow(-1, 1), pow(-1, 1)); }
END_TEST

START_TEST(test_16) { ck_assert_ldouble_eq(s21_pow(-2, -3), pow(-2, -3)); }
END_TEST

START_TEST(test_17) {
  ck_assert_ldouble_eq(s21_pow(625.25, 0), pow(625.25, 0));
}
END_TEST

START_TEST(test_18) { ck_assert_double_eq(s21_pow(0.0, -2.0), pow(0.0, -2.0)); }
END_TEST

START_TEST(test_19) {
  ck_assert_double_eq(s21_pow(0.0, S21_INF), pow(0.0, S21_INF));
}
END_TEST

START_TEST(test_20) {
  ck_assert_double_eq(s21_pow(-1, S21_INF), pow(-1, S21_INF));
}
END_TEST

START_TEST(test_21) {
  ck_assert_double_eq(s21_pow(-1, S21_INF_NEGATIV), pow(-1, S21_INF_NEGATIV));
}
END_TEST

START_TEST(test_22) {
  ck_assert_double_eq(s21_pow(-1, S21_MAX_NUM), pow(-1, S21_MAX_NUM));
}
END_TEST

START_TEST(test_23) {
  ck_assert_double_eq(s21_pow(0.9, S21_INF), pow(0.9, S21_INF));
}
END_TEST

START_TEST(test_24) {
  ck_assert_double_eq(s21_pow(-0.7, S21_INF), pow(-0.7, S21_INF));
}
END_TEST

START_TEST(test_25) {
  ck_assert_double_eq(s21_pow(-0.5, S21_MAX_NUM), pow(-0.5, S21_MAX_NUM));
}
END_TEST

START_TEST(test_26) {
  ck_assert_double_eq(s21_pow(0.1, S21_MAX_NUM), pow(0.1, S21_MAX_NUM));
}
END_TEST

START_TEST(test_27) {
  ck_assert_double_eq(s21_pow(-0.2, S21_INF_NEGATIV),
                      pow(-0.2, S21_INF_NEGATIV));
}
END_TEST

START_TEST(test_28) {
  ck_assert_double_eq(s21_pow(0.2, S21_INF_NEGATIV), pow(0.2, S21_INF_NEGATIV));
}
END_TEST

START_TEST(test_29) {
  ck_assert_double_eq(s21_pow(2, S21_INF), pow(2, S21_INF));
}
END_TEST

START_TEST(test_30) {
  ck_assert_double_eq(s21_pow(2, S21_INF_NEGATIV), pow(2, S21_INF_NEGATIV));
}
END_TEST

START_TEST(test_31) {
  ck_assert_double_eq(s21_pow(S21_INF, 2), pow(S21_INF, 2));
}
END_TEST

START_TEST(test_32) {
  ck_assert_double_eq(s21_pow(S21_INF, -4), pow(S21_INF, -4));
}
END_TEST

START_TEST(test_33) {
  ck_assert_double_eq(s21_pow(S21_INF_NEGATIV, 1.2), pow(S21_INF_NEGATIV, 1.2));
}
END_TEST

START_TEST(test_34) {
  ck_assert_double_eq(s21_pow(S21_MAX_NUM, 4.2), pow(S21_MAX_NUM, 4.2));
}
END_TEST

START_TEST(test_35) {
  ck_assert_double_eq(s21_pow(S21_INF_NEGATIV, 5), pow(S21_INF_NEGATIV, 5));
}
END_TEST

START_TEST(test_36) {
  ck_assert_double_eq(s21_pow(S21_MAX_NUM, -2), pow(S21_MAX_NUM, -2));
}
END_TEST

START_TEST(test_37) {
  ck_assert_double_eq_tol(s21_pow(12.5, 9.5), pow(12.5, 9.5), 1e-6);
}
END_TEST

START_TEST(test_38) { ck_assert_double_nan(s21_pow(S21_NAN, -4)); }
END_TEST

START_TEST(test_39) { ck_assert_double_eq(s21_pow(-0.0, -1), pow(-0.0, -1)); }
END_TEST

START_TEST(test_40) {
  ck_assert_double_eq(s21_pow(-0.0, -1.25), pow(-0.0, -1.25));
}
END_TEST

START_TEST(test_41) {
  ck_assert_double_nan(s21_pow(-1, -1.25));
  ck_assert_double_nan(pow(-1, -1.25));
}
END_TEST

START_TEST(test_42) { ck_assert_double_eq(s21_pow(-1, 3), pow(-1, -3)); }
END_TEST

Suite *suite_s21_pow(void) {
  Suite *s = suite_create("\033[45m-=S21_POW=-\033[0m");
  TCase *tc = tcase_create("pow_tc");

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
  tcase_add_test(tc, test_23);
  tcase_add_test(tc, test_24);
  tcase_add_test(tc, test_25);
  tcase_add_test(tc, test_26);
  tcase_add_test(tc, test_27);
  tcase_add_test(tc, test_28);
  tcase_add_test(tc, test_29);
  tcase_add_test(tc, test_30);
  tcase_add_test(tc, test_31);
  tcase_add_test(tc, test_32);
  tcase_add_test(tc, test_33);
  tcase_add_test(tc, test_34);
  tcase_add_test(tc, test_35);
  tcase_add_test(tc, test_36);
  tcase_add_test(tc, test_37);
  tcase_add_test(tc, test_38);
  tcase_add_test(tc, test_39);
  tcase_add_test(tc, test_40);
  tcase_add_test(tc, test_41);
  tcase_add_test(tc, test_42);

  suite_add_tcase(s, tc);
  return s;
}
