#include "s21_math.h"

long double s21_sin(double x) {
  long double lx = 0;

  if (x != x) {
    lx = S21_NAN;
  }

  if (x == S21_INF || x == S21_INF_NEGATIV) {
    lx = S21_NAN;
  }

  if (!lx) {
    x = s21_fmod(x, (S21_PI * 2.0));
    if (x > 3 * S21_PI / 2.0) {
      x -= S21_PI;
      long double rel = x - S21_PI / 2;
      x = S21_PI / 2 - rel;
      lx = (-(s21_sin_calc(x)));
    } else if (x >= S21_PI && x <= 3 * S21_PI / 2.0) {
      x -= S21_PI;
      lx = (-(s21_sin_calc(x)));
    } else if (x < S21_PI && x >= S21_PI / 2.0) {
      x = S21_PI - x;
      lx = (s21_sin_calc(x));
    } else {
      lx = s21_sin_calc(x);
    }
  }
  return lx;
}

long double s21_sin_calc(double x) {
  short int sign = 1;
  long double num = x, denum = 1, res = x;
  for (int i = 3; i < 60; i += 2) {
    sign = -sign;
    num = num * x * x;
    denum = denum * i * (i - 1);
    res += sign * (num / denum);
  }
  return res;
}