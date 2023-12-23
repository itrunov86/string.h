#include "s21_math.h"

long double s21_floor(double x) {
  long double int_main = 0;

  if (x == S21_INF || x == S21_INF_NEGATIV || x != x) {
    int_main = x;

  } else {
    int_main = (long int)x;

    if (x < 0 && int_main != x) int_main--;
  }

  return int_main;
}