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

void test( struct TEST_DATA *test, int num, FILE *f );
void test_reader( struct TEST_DATA *test, FILE *f );
