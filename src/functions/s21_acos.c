#include "s21_math.h"

long double s21_acos(double x) {
  long double lx = 0;

  if (x != x) {
    x = S21_NAN;
  }
  if (x == S21_INF || x == S21_INF_NEGATIV) {
    x = S21_NAN;
  }
  lx = S21_PI / 2 - s21_asin(x);

  return lx;
}