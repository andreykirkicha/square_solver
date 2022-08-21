const int AMOUNT = 10;
const int ANS_LEN = 16;
const int START_VAL = -27;

struct TEST_DATA {
    double a;
    double b;
    double c;
    double x1;
    double x2;
    char res[ANS_LEN];
};

void test(double a, double b, double c, double test_x1, double test_x2, char test_res[], int num, FILE *f);
void test_reader(struct TEST_DATA *test, FILE *f);
