#include "s21_math.h"

long double s21_ceil(double x) {
  long double lx = 0;

  if (x == S21_INF || x == S21_INF_NEGATIV || x != x) {
    lx = x;
  }

  if (!lx) {
    lx = (long double)x;
    if (lx > (long int)lx) lx = (long int)lx + 1.0;
    if (lx < 0) lx = (long int)lx;
  }

  return lx;
}
