#include "s21_math.h"

long double s21_asin(double x) {
  long double lx = 0;
  if (x < -1 || x > 1) {
    lx = S21_NAN * (-1);
  }
  if (x != x) {
    lx = S21_NAN;
  }
  if (x == S21_INF || x == S21_INF_NEGATIV) {
    lx = S21_NAN;
  }
  if (!lx) {
    lx = s21_atan(x / s21_sqrt(1 - (x * x)));
  }
  return lx;
}
