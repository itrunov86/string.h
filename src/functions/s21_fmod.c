#include "s21_math.h"
#include <math.h>
#include <stdio.h>

long double s21_fmod(double x, double y) {
  long double lx = 0;

  if (y != y || x != x || y == 0.0) {
    lx = S21_NAN;
  }

  if (x == S21_INF || x == S21_INF_NEGATIV) {
    lx = S21_NAN;
  } else if (y == S21_INF || y == S21_INF_NEGATIV) {
    lx = x;
  }

  if (!lx) {
    long long int full = x / y;
    lx = (long double)x - (long double)y * full;
  }

  return lx;
}

// int main()
// {
//   double x = 1E14;
//   double y = S21_PI * 2;

//   printf("orig = %.10f\n", fmod(x, y));
//   printf("team = %.10Lf\n", s21_fmod(x, y));


//   return 0;
// }