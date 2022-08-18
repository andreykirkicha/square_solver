#include <errno.h>

enum {INF_ROOTS, ONE_ROOT, TWO_ROOTS, NO_ROOTS};
enum {NOT_NUM = -1, PTR_NULL = -2, TOO_BIG = -3, TOO_BIG_CALC = -4};
const double EPS = 0.000002;
const int ERRLEN = 28;

int reader(double *a);
int input_coefficient(double *a, double *b, double *c);
int squaresolver(double a, double b, double c, double *x1, double *x2);
int linsolver(double b, double c, double *x1);
void printer(int res, double x1, double x2);
void errorhunter(int n);
int limits(double n);
