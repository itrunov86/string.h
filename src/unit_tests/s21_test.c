#include "s21_test.h"

void run_tests() {
  Suite *list_cases[] = {suite_s21_abs(),    // 1 Eg
                         suite_s21_ceil(),   // 5 Eg
                         suite_s21_cos(),    // 6 Dm
                         suite_s21_exp(),    // 7 Eg
                         suite_s21_fabs(),   // 8 Il
                         suite_s21_floor(),  // 9 Dm
                         suite_s21_fmod(),   // 10 Dm
                         suite_s21_log(),
                         suite_s21_pow(),   // 12 Il
                         suite_s21_sin(),   // 13 Dm
                         suite_s21_sqrt(),  // 14 Vt
                         suite_s21_tan(),   // 15 Eg
                         suite_s21_atan(),  suite_s21_acos(),
                         suite_s21_asin(),  NULL};
  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;
  if (counter_testcase > 0) putchar('\n');
  counter_testcase++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

int main(void) {
  run_tests();
  return 0;
}
