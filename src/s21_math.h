#ifndef S21_MATH
#define S21_MATH

#define S21_PI 3.14159265358979323846L
#define S21_EXP 2.71828182845904
#define S21_INF 1.0 / 0.0
#define S21_INF_NEGATIV -1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define S21_MAX_NUM 1.7976931348623157e308
#define S21_EPS 1e-20
#define s21_isNAN(x) (x != x)

int s21_abs(int n);
long double s21_ceil(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_pow(double base, double exp);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_sin(double x);
long double s21_cos(double x2);
long double s21_tan(double x);
long double s21_sqrt(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);

long double factorial(int n);
long double s21_fmodl(long double x, long double y);
long double s21_powl(long double base, long double exp);
long double s21_sinl(long double x);
long double s21_cosl(long double x);
long double s21_expl(long double x);
long double s21_logl(long double x);
long double s21_fabsl(long double x);
long double s21_sin_calc(double x);

#endif