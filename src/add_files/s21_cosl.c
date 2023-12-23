#include <math.h>

#include "s21_math.h"

long double s21_cosl(long double x) {
  long double lx = 0;

  if (x == S21_INF || x == S21_INF_NEGATIV || x == S21_NAN) {
    lx = S21_NAN;
  } else if (!lx) {
    x = s21_fmodl(x, 2 * S21_PI);

    //  long double r = 1;
    long double sign = 1;

    for (int i = 0; i < 80; i++) {
      lx += sign * s21_powl(x, 2 * i) / (factorial(2 * i));
      sign = -sign;
    }

    // lx=r;
  }

  return lx;
}