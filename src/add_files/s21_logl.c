#include "s21_math.h"

long double s21_logl(long double x) {
  long double res = 0;
  if (x == 0) {
    res = S21_INF_NEGATIV;
  } else if (x < 0) {
    res = S21_NAN;
  } else if (x == S21_INF) {
    res = S21_INF;
  } else {
    for (int i = 1; i <= 150; ++i) {
      long double x_new = res;
      res = x_new + 2 * ((x - s21_expl(x_new)) / (x + s21_expl(x_new)));
    }
  }

  return res;
}