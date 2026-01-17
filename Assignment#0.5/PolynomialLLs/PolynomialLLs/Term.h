#ifndef H_Term
#define H_Term

#include <iomanip>
using namespace std;

struct Term{
    int coeff;
    int exp;
    Term* next;
};
#endif // H_Term
