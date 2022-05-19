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
    
    //BINARY OPERATORS
    Fraction operator+(Fraction f2);
    Fraction operator-(Fraction f2);
    Fraction operator=(Fraction f2);
    Fraction operator/(Fraction f2);
    Fraction operator*(Fraction f2);
    Fraction &operator+=(Fraction f2);
    Fraction &operator-=(Fraction f2);
    Fraction &operator/=(Fraction f2);
    Fraction &operator*=(Fraction f2);
    
    //UNARY OPERATORS
    Fraction operator++(void);
    Fraction operator++(int);
    Fraction operator--(void);
    Fraction operator--(int);
    Fraction operator~(void);
    Fraction operator-(int);
    
    // IN/OUT OPERATORS
    friend ostream& operator<<(ostream& out, const Fraction& fract);
    friend istream& operator>>(istream& in, Fraction& fract);

    // BOOLEAN OPERATORS
    bool operator>(Fraction f2);
    bool operator>=(Fraction f2);
    bool operator<(Fraction f2);
    bool operator<=(Fraction f2);
    bool operator==(Fraction f2);
    bool operator!=(Fraction f2) const;
    bool operator!(void);

    //CASTING FUNCTIONS
    operator double(void);
    operator float(void);
    
    void reduce(void);
    void reduce(int & numerator,int & denominator);

};






#endif /* fraction_hpp */
