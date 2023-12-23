#include "s21_math.h"

long double s21_fmodl(long double x, long double y) {
  /*     if(y == S21_NAN || y == 0.0 || x==S21_INF || x == S21_INF_NEGATIV || x
    == S21_NAN)
    {
       return S21_NAN;
    } */
  long double lx = 0;

  if (y != y || x != x) {
    lx = S21_NAN;
  }
  if (y == 0.0) {
    lx = S21_NAN;
  }
  if (x == S21_INF || x == S21_INF_NEGATIV) {
    lx = S21_NAN;
  }
  if (y == S21_INF || y == S21_INF_NEGATIV) {
    lx = x;
  }

  if (!lx) {
    int full = x / y;
    lx = x - y * full;
    /*     lx = x;
        if (lx == s21_fabs(x))
        {
          while (lx > 0)
          {
            lx = lx - s21_fabs(y);
          }
          lx < 0 ? (lx = lx + s21_fabs(y)) : lx;
        }
        else
        {
          while (lx < 0)
          {
            lx = lx + s21_fabs(y);
          }
          lx > 0 ? (lx = lx - s21_fabs(y)) : lx;
        } */
  }
  return lx;
}