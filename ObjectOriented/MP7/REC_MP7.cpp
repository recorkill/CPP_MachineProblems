#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include "fraction.h"

using namespace std;

int main()
{
    cout << "Ryan Corkill\nCPS 271\nMarch 17, 2022\nMachine Problem 7" << endl << endl;
    
    //Create two character-based fractions
    Fraction<char> f1('a', 'b');
    Fraction<char> f2('c', 'd');
    
    //Display the values of the two fractions
    cout << "Fraction 1: " << f1 << "   Fraction 2: " << f2 << endl << endl;
    
    //Generate results for all four operations on the fractions
    Fraction<char> sum = (f1+f2);
    Fraction<char> difference = (f1-f2);
    Fraction<char> quotient = (f1/f2);
    Fraction<char> product = (f1*f2);
    
    //Print the results of each operation
    cout << "The sum of Fractions 1 and 2 is: " << sum << endl << endl;
    cout << "The difference of Fractions 1 and 2 is: " << difference << endl << endl;
    cout << "The quotient of Fractions 1 and 2 is: " << quotient << endl << endl;
    cout << "The product of Fractions 1 and 2 is: " << product << endl << endl;

}
