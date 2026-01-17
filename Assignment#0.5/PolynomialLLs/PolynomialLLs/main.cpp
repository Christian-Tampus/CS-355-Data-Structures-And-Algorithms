#include <iostream>
#include "Poly.h"
#include <fstream>

using namespace std;

int main()
{
    ifstream myfile ("poly.txt");

    Poly myPoly;

    myPoly.Insert(5, 4);
    myPoly.Insert(3, 3);
    myPoly.Insert(17, 1);

    cout<<myPoly<<endl;
    cout<<"Evaluate at x=2"<<endl;
    cout<<myPoly.Evaluate(2)<<endl;

    myPoly.Insert(6, 8);
    myPoly.Insert(2, 6);

    myPoly.PrintReverse();

    myPoly.Insert(5, 0);
    cout<<myPoly<<endl;

    cout<<myPoly.Search(6)<<endl;
    cout<<myPoly.Search(7)<<endl;

    Poly copyPoly;
    copyPoly = myPoly;
    copyPoly.Insert(2, 2);
    copyPoly.Insert(9, 9);
    myPoly.Insert(7, 7);

    Poly result;
    cout<<myPoly<<endl;
    cout<<copyPoly<<endl;
    cout<<"********Adding********"<<endl;
    result = myPoly + copyPoly;
    cout<<result<<endl;
    cout<<"****************"<<endl;

    cout<<"********Subtracting********"<<endl;
    result = myPoly - copyPoly;
    cout<<result<<endl;
    cout<<"****************"<<endl;

    cout<<"****************"<<endl;
    cout<<copyPoly<<endl;
    cout<<"Derivation One"<<endl;
    copyPoly.Derivative();
    cout<<copyPoly<<endl;

    cout<<"Derivation Two"<<endl;
    copyPoly.Derivative();
    cout<<copyPoly<<endl;

    cout<<"Derivation Three"<<endl;
    copyPoly.Derivative();
    cout<<copyPoly<<endl;
    cout<<"****************"<<endl;

    myPoly.Reset();
    cout<<myPoly<<endl;
    cout<<myPoly.Evaluate(2)<<endl;
    cout<<copyPoly<<endl;

    cout<<"********Use >>*******"<<endl;
    Poly p3;
    //cin >> p3;
    myfile >> p3;
    cout<<p3<<endl;

    myfile.close();
    return 0;
}
