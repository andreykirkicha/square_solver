const int AMOUNT = 10;
const int ANS_LEN = 11;

struct IN {
    double a;
    double b;
    double c;
};

struct OUT {
    double x1;
    double x2;
    double res;
};

struct ANS {
    double x1;
    double x2;
    char ans[ANS_LEN];
};

void test(struct IN[], struct OUT[], struct ANS[], int);
