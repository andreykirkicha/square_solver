#include <errno.h>

enum roots {
    INF_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    NO_ROOTS = 3
};
enum errors {
    NOT_NUM = -1,
    PTR_NULL = -2,
    TOO_BIG = -3,
    TOO_BIG_CALC = -4,
    INF_NAN = -5
};
const double EPS = 0.000002;
const int ERRLEN = 28;

int reader(double *a);
int input_coefficient(double *a, double *b, double *c);
int squaresolver(double a, double b, double c, double *x1, double *x2);
int linsolver(double b, double c, double *x1);
void printer(int res, double x1, double x2);
void error_handler(int error);
int not_in_range(double num);
int cmp_double(double a, double b, double lim);
