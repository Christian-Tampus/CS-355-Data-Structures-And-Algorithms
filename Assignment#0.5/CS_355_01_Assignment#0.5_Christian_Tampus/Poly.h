// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #0.5
// Date due: 01/12/2025
// Description: The program is designed to represent a polynomial using a linkedlist class data structure.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_Poly
#define H_Poly
//Dependencies
#include <iostream>
#include <cmath>
#include <string>
#include "Term.h"
//Using Directives
using namespace std;
//Class Declarations
class Poly
{
//Private members
private:
	//LinkedList head node pointer
    Term* head;
    //Private helper methods
    void recPrintRev(Term*);
    void copyList(const Poly& otherList);
//Public members
public:
	//Constructors
    Poly();
    Poly(const Poly&);
    //Extraction & Insertion operator overloads
    friend istream& operator>>(istream&, Poly&);
    friend ostream& operator<<(ostream&, const Poly&);
    //Reset & Evaluate methods
    void Reset();
    int Evaluate(int);
    //Addition & Subtraction operator overloads
    Poly operator+(const Poly&)const;
	Poly operator-(const Poly&)const;
	//Derivative, Insertion, Search & PrintReverse methods
	void Derivative();
	void Insert(int, int);
    Term* Search(int);
    void PrintReverse();
    //Assignment operator overload
    Poly& operator=(const Poly&);
    //Destructor
    ~Poly();
};
#endif // H_Poly