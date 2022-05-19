#ifndef fraction_hpp
#define fraction_hpp

#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class Fraction
{
    int numerator;
    int denominator;
    
public:
    
    void Print();
    void Input();
    
    Fraction();
    Fraction(int nume);
    Fraction(double nume);
    Fraction(int nume, int denom);
    
    
    // IN/OUT OPERATORS
    friend ostream& operator<<(ostream& out, const Fraction& fract);
    friend istream& operator>>(istream& in, Fraction& fract);

    
    void reduce(void);
    void reduce(int & numerator,int & denominator);
    
    bool operator>(Fraction f2);
    bool operator<(Fraction f2);
    
    bool operator==(Fraction f2);
};





#endif /* fraction_hpp */
