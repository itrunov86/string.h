#include "s21_math.h"

long double factorial(int n) {
  if (n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}
