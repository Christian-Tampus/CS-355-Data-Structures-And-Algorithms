// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #0.5
// Date due: 01/12/2025
// Description: The program is designed to represent a polynomial using a linkedlist class data structure.
// ---------------------------------------------------------------------------
//Dependencies
#include <iostream>
#include "Poly.h"
#include <fstream>
//Using Directives
using namespace std;
//Main
int main()
{
    //variable declarations
	ifstream myfile ("poly.txt");
	//test constructor w/no parameters
    Poly myPoly;
    //test insert method
    myPoly.Insert(5, 4);
    myPoly.Insert(3, 3);
    myPoly.Insert(17, 1);
    //test insertion operator
    std::cout << myPoly << std::endl;
    //test evaluate method w/insertion operator
    std::cout << "Evaluate at x=2" << std::endl;
    std::cout << myPoly.Evaluate(2) << std::endl;;
    //test insert method
    myPoly.Insert(6, 8);
    myPoly.Insert(2, 6);
    //test printreverse method
    myPoly.PrintReverse();
    //test insert method
    myPoly.Insert(5, 0);
     //test insertion operator
    std::cout << myPoly << std::endl;
    //test search method w/insertion operator
    std::cout << myPoly.Search(6) << std::endl;
    std::cout << myPoly.Search(7) << std::endl;
    //test constructor w/no parameters
    Poly copyPoly;
    //test assignment operator
    copyPoly = myPoly;
    //test insert method
    copyPoly.Insert(2, 2);
    copyPoly.Insert(9, 9);
    myPoly.Insert(7, 7);
    //test constructor w/no parameters
    Poly result;
    //test insertion operator
    std::cout << myPoly << std::endl;
    std::cout << copyPoly << std::endl;
    std::cout << "********Adding********" << std::endl;
    //test assignment operator w/addition operator
    result = myPoly + copyPoly;
    //test insertion operator
    std::cout << result << endl;
    std::cout << "****************" << std::endl;
    std::cout <<"********Subtracting********" << std::endl;
    //test assignment operator w/subtraction operator
    result = myPoly - copyPoly;
    //test insertion operator
    std::cout << result << std::endl;
    std::cout << "****************" << std::endl;
    std::cout << "****************" << std::endl;
    //test insertion operator
    std::cout << copyPoly << endl;
    std::cout << "Derivation One" << std::endl;
    //test derivative method
    copyPoly.Derivative();
    //test insertion operator
    std::cout << copyPoly << std::endl;
    std::cout<<"Derivation Two"<<std::endl;
    //test derivative method
    copyPoly.Derivative();
    //test insertion operator
    std::cout << copyPoly << std::endl;
    std::cout<<"Derivation Three"<<std::endl;
    //test derivative method
    copyPoly.Derivative();
    //test insertion operator
    std::cout << copyPoly << std::endl;
    std::cout << "****************" << std::endl;
    //test reset method
    myPoly.Reset();
    //test insertion operator
    std::cout << myPoly << std::endl;
    //test insertion w/evaluate method
    std::cout << myPoly.Evaluate(2) << std::endl;
    //test insertion operator
    std::cout << copyPoly << std::endl;
    std::cout << "********Use >>*******" << std::endl;
    //test constructor w/no parameters
    Poly p3;
    //cin >> p3;
    //test extraction operator
    myfile >> p3;
    //test insertion operator
    std::cout << p3 << std::endl;
    myfile.close();
    return 0;
};