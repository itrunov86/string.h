#include "s21_math.h"

long double s21_tan(double x) {
  long double lx = 0;

  if (x != x) {
    lx = S21_NAN;
  }
  if (x == S21_INF || x == S21_INF_NEGATIV) {
    lx = S21_NAN;
  }

  if (!lx) {
    lx = x;
    if (lx != 0) {
      lx = s21_sinl(lx) / s21_cosl(lx);
    }
  }
  return lx;
}