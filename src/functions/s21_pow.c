#include "s21_math.h"

#define OK 2

typedef union {
  long double value;
  struct {
    unsigned long mantissa : 64;
    unsigned int exp : 15;
    unsigned char sign : 1;
  } part;
} u_test;

long double check_pow(double base, double exp) {
  long double res = OK;
  u_test t = {.value = base};
  if (exp == 0 || base == 1) {
    res = 1;
  } else if (s21_isNAN(exp) || s21_isNAN(base)) {
    res = S21_NAN;
  } else if (exp == 1) {
    res = base;
  } else if (t.part.sign == 1 && t.part.exp == 0 && t.part.mantissa == 0 &&
             exp == -1.0) {
    res = S21_INF_NEGATIV;
  } else if (base == 0) {
    if (exp < 0) {
      res = S21_INF;
    } else if (exp == S21_INF) {
      res = 0;
    } else {
      res = 0;
    }
  } else if (base == -1) {
    if (exp == S21_INF || exp == S21_INF_NEGATIV || exp == S21_MAX_NUM) {
      res = 1;
    } else if ((int)exp != exp) {
      res = S21_NAN;
    } else if ((int)exp % 2 == 0) {
      res = 1;
    } else {
      res = -1;
    }
  } else if (exp == S21_INF || exp == S21_MAX_NUM) {
    if (base > -1 && base < 1) {
      res = 0;
    } else {
      res = S21_INF;
    }
  } else if (exp == S21_INF_NEGATIV) {
    if (base > -1 && base < 1) {
      res = S21_INF;
    } else {
      res = 0;
    }
  } else if (base == S21_INF) {
    if (exp > 0) {
      res = S21_INF;
    } else {
      res = 0;
    }
  } else if (base == S21_INF_NEGATIV && (int)exp != exp) {
    res = S21_INF;
  } else if (base < 0 && (int)exp != exp) {
    res = S21_NAN;
  } else if (base == S21_MAX_NUM && exp > 1) {
    res = S21_INF;
  }
  return res;
}

long double s21_pow(double base, double exp) {
  long double res = 1;
  res = check_pow(base, exp);
  if (res == OK) {
    res = 1;
    if ((int)exp == exp) {
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
  }
  return res;
}
