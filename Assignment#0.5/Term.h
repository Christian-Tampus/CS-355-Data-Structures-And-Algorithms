// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #0.5
// Date due: 01/12/2025
// Description: The program is designed to represent a polynomial using a linkedlist class data structure.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_Term
#define H_Term
//Dependencies
#include <iomanip>
//Using Directives
using namespace std;
//Structs
struct Term{
	int coefficient; //Renamed coeff -> coefficient for improved legibility
	int exponent; //Renamed exp -> exponent for improved legibility
	Term* next;
};
#endif // H_Term