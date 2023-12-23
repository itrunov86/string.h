#include "s21_math.h"

long double s21_powl(long double base, long double exp) {
  long double res = 1;
  if (exp == 0 || base == 1) {
    res = 1;
  } else if (s21_isNAN(exp) || s21_isNAN(base)) {
    res = S21_NAN;
  } else if (exp == 1) {
    res = base;
  } else if (base == 0) {
    if (exp < 0 /*|| exp == S21_INF_NEGATIV*/) {
      res = S21_INF;
    } else if (exp == S21_INF) {
      res = 0;
    } else {
      res = 0;
    }
  } else if (base == -1 &&
             (exp == S21_INF || exp == S21_INF_NEGATIV || exp == S21_MAX_NUM)) {
    res = 1;
  } else if (exp == S21_INF || exp == S21_MAX_NUM) {
    if ((int)base != base && base > -1 && base < 1 && base != 0) {
      res = 0;
    } else {
      res = S21_INF;
    }
  } else if (exp == S21_INF_NEGATIV) {
    if ((int)base != base && base > -1 && base < 1 && base != 0) {
      res = S21_INF;
    } else {
      res = 0;
    }
  } else if (base < 0 && (int)exp != exp) {
    res = S21_NAN;
  } else if (base == S21_INF) {
    if (exp > 0) {
      res = S21_INF;
    } else if (exp < 0) {
      res = 0;
    }
  } else if (base == S21_INF_NEGATIV && (int)exp != exp) {
    res = S21_INF;
  } else if (base == S21_MAX_NUM && exp > 1) {
    res = S21_INF;
  } else if ((int)exp == exp) {
    while (exp)
      if (exp > 0) {
        res *= base;
        --exp;
      } else {
        res /= base;
        ++exp;
      }
  } else {
    res = s21_expl(exp * s21_logl(base));
  }

  return res;
}