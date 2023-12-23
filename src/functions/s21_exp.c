#include "s21_math.h"

long double s21_exp(double x) {
  long double num_add = 1.0;
  long double numbers = 1.0;
  int flag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  for (long double n = 1.0; s21_fabs((double)num_add) > S21_EPS; n++) {
    num_add *= x / n;
    numbers += num_add;
    if (numbers > S21_MAX_NUM) {
      numbers = S21_INF;
      break;
    }
  }

  if (flag) {
    if (numbers > S21_MAX_NUM)
      numbers = 0.0;
    else
      numbers = 1.0 / numbers;
  }

  if (numbers > S21_MAX_NUM) numbers = S21_INF;

  return numbers;
}