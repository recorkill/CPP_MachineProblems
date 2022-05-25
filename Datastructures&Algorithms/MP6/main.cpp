#include <iostream>
#include <string>
#include "Complex.h"

using namespace std;

void testMP6()
{
    string s_entry1, s_entry2;
    Complex entry1, entry2; //two complex numbers to be entered
    Complex sum, difference, product, quotient; //resulting complex numbers for each operation
    
    cout << "Please enter the first complex number in the form a+bi.\nComplex 1: ";
    cin >> s_entry1;
    entry1.convertStringToComplex(s_entry1);
    
    cout << "Please enter the second complex number in the form a+bi.\nComplex 2: ";
    cin >> s_entry2;
    entry2.convertStringToComplex(s_entry2);
    
    //Add
    sum = entry1 + entry2;
    
    //Subtract
    difference = entry1 - entry2;
    
    //Multiply
    product = entry1 * entry2;
    
    //Divide
    quotient = entry1 / entry2;
    
    cout << "\n***Adding***\n" << "(" << entry1 << ")+(" << entry2 << ") = " << sum << endl;
    cout << "\n***Subtracting***\n" << "(" << entry1 << ")-(" << entry2 << ") = " << difference << endl;
    cout << "\n***Multiplying***\n" << "(" << entry1 << ")*(" << entry2 << ") = " << product << endl;
    cout << "\n***Dividing***\n" << "(" << entry1 << ")/(" << entry2 << ") = " << quotient << endl << endl;
    
}


int main()
{
    cout << "Ryan Corkill\nCPS 272\nApril 25, 2022\nMachine Problem 6, Algorithms\n" << endl;
    
    testMP6();
    
}
