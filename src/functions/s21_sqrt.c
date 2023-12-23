#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res = 0.0;
  if (x < 0) {
    return res = -S21_NAN;
  } else if (x == 0 || x == 1) {
    res = x;
  } else {
    res = s21_pow(x, 0.5);
  }
  return res;
}