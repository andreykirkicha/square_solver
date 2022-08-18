#include <errno.h>

extern int errno;

enum {INF_ROOTS, ONE_ROOT, TWO_ROOTS, NO_ROOTS};
const double EPS = 0.000002;
const int ERRLEN = 28;

int reader(double *a);
int input_coefficient(double *a, double *b, double *c);
int squaresolver(double a, double b, double c, double *x1, double *x2);
int linsolver(double b, double c, double *x1);
void printer(int res, double x1, double x2);
void err(int n);
int limits(double n);
