#include "s21_math.h"

int s21_abs(int x) {
  int new_x = 0;
  x = (int)x;
  if (x < 0) x = -x;
  if (x > 9) {
    int discharge = 1;
    for (int i = 0; x > 9; i++) {
      if (i > 0) discharge = discharge * 10;
      new_x = new_x + (x % 10) * discharge;
      x = x / 10;
    }
    discharge = discharge * 10;
    new_x = new_x + (x % 10) * discharge;
  } else
    new_x = (int)x;
  return new_x;
}