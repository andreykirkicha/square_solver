enum {INF_ROOTS, ONE_ROOT, TWO_ROOTS, NO_ROOTS};

int reader(double *a);
int input_coefficient(double *a, double *b, double *c);
int squaresolver(double a, double b, double c, double *x1, double *x2);
int linsolver(double b, double c, double *x1);
void printer(int res, double *x1, double *x2);
