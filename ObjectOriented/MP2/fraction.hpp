#ifndef fraction_hpp
#define fraction_hpp

#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;

class Fraction
{
    int numerator;
    int denominator;
    
public:
    
    void Print();
    void Input();
    
    //Constructors
    Fraction();
    Fraction(int nume);
    Fraction(double nume);
    Fraction(int nume, int denom);
    
    //Single-input operations
    Fraction addFraction(Fraction to_be_added);
    Fraction subtractFraction(Fraction to_be_subtrated);
    Fraction multiplyFraction(Fraction to_be_multiplied);
    Fraction divideFraction(Fraction to_be_divided);
    
    //Double-input operations 
    Fraction addFraction(Fraction fract1, Fraction fract2);
    Fraction subtractFraction(Fraction fract1, Fraction fract2);
    Fraction multiplyFraction(Fraction fract1, Fraction fract2);
    Fraction divideFraction(Fraction fract1, Fraction fract2);
};

#endif /* fraction_hpp */
