#include <math.h>

#include "s21_math.h"

long double s21_sinl(long double x) {
  long double lx = 0;

  if (x != x) {
    lx = S21_NAN;
  }
  if (x == S21_INF || x == S21_INF_NEGATIV) {
    lx = S21_NAN;
  }

  if (!lx) {
    x = s21_fmodl(x, 2 * S21_PI);

    //   long double r = lx;
    long double sign = 1;

    for (int i = 0; i < 80; i++) {
      lx += (sign * s21_powl(x, 1 + 2 * i)) / (factorial(1 + 2 * i));
      sign = -sign;
    }
    // lx = r;
  }

  return lx;
}