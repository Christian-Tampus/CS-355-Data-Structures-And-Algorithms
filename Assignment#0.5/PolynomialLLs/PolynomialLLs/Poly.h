#ifndef H_Poly
#define H_Poly

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#include "Term.h"

class Poly
{
public:
    Poly();
    Poly(const Poly&);

    friend istream& operator>>(istream&, Poly&);
    friend ostream& operator<<(ostream&, const Poly&);

    void Reset();
    int Evaluate(int);

    Poly operator+(const Poly&)const;
	Poly operator-(const Poly&)const;

	void Derivative();

	void Insert(int, int);

    Term* Search(int);

    void PrintReverse();

    Poly& operator=(const Poly&);

    ~Poly();



private:
    Term* head;

    void recPrintRev(Term*);
    void copyList(const Poly& otherList);
};

#endif // H_Poly
