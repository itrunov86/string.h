#include "s21_math.h"

long double s21_atan(double x) {
  long double xs = 0;
  int sign = 1;
  int iterations = 80;
  double x1 = s21_fabs(x);
  if (x != x) {
    xs = x;
  } else if (x1 < 1) {
    if (x1 > 0.9) {
      iterations = 1000000;
    }
    double x2 = x1;
    for (int k = 0; k < iterations; k++) {
      xs += sign * x2 / (1 + 2 * k);
      x2 *= (x1 * x1);
      sign = -sign;
    }
  } else if (x1 > 1) {
    if (x1 < 1.1) {
      iterations = 1000000;
    }
    double x2 = 1 / x1;
    for (int k = 0; k < iterations; k++) {
      xs += sign * x2 / (1 + 2 * k);
      x2 *= 1 / (x1 * x1);
      sign = -sign;
    }
    xs = S21_PI / 2 - xs;
  } else {
    xs = S21_PI / 4;
  }

  if (x < 0) {
    xs = -xs;
  }

  return xs;
}