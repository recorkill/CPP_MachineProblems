#include "fraction.hpp"
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int nume)
{
    numerator = nume;
    denominator = 1;
}

Fraction::Fraction(double nume)
{
    numerator = nume*100000;
    denominator = 100000;
}


Fraction::Fraction(int nume, int denom)
{
    //Handling the entry of a fraction with denominator = 0
    if(denom == 0)
    {
        cout << "Invalid entery, denominator cannot be zero. This fraction will be set to the default value of 0/1" << endl;
        numerator = 0;
        denominator = 1;
    }
    else
    {
        numerator = nume;
        denominator = denom;
    }
}

void Fraction::Print()
{
    cout << numerator << "/" << denominator;
}

// INPUT()
void Fraction::Input()
{
    cout << "Enter a new numerator value: ";
    cin >> numerator;
    cout << "Enter a new denominator value: ";
    cin >> denominator;
    //ERROR HANDLING
    while(denominator == 0)
    {
        cout << "\nINVALID ENTERY --- the denominator cannot equal zero.\nPlease enter a non-zero value for the denominator: ";
        cin >> denominator;
    }
    Fraction::reduce();
}
// + OPERATOR
Fraction Fraction::operator+(Fraction f2)
{
    Fraction fract((numerator*f2.denominator)+(denominator*f2.numerator), (denominator*f2.denominator));
    fract.reduce();
    return fract;
}
//   +=
Fraction &Fraction::operator+=(Fraction f2)
{
    *this = *this + f2;
    Fraction::reduce();
    return *this;
}

// - OPERATOR
Fraction Fraction::operator-(Fraction f2)
{
    Fraction fract((numerator*f2.denominator)-(denominator*f2.numerator), (denominator*f2.denominator));
    fract.reduce();
    return fract;
}
//   -=
Fraction &Fraction::operator-=(Fraction f2)
{
    *this = *this - f2;
    Fraction::reduce();
    return *this;
}

// * OPERATOR
Fraction Fraction::operator*(Fraction f2)
{
    Fraction fract((numerator*f2.numerator), (denominator*f2.denominator));
    fract.reduce();
    return fract;
}
//   *=
Fraction &Fraction::operator*=(Fraction f2)
{
    *this = *this * f2;
    Fraction::reduce();
    return *this;
}

// / OPERATOR
Fraction Fraction::operator/(Fraction f2)
{
    //Because we handle any issues that could occur from a zero-denominator fraction in the Input() fxn, we know that both fractions are safe to use here
    Fraction fract((numerator*f2.denominator), (denominator*f2.numerator));
    fract.reduce();
    return fract;
}
//   /=
Fraction &Fraction::operator/=(Fraction f2)
{
    *this = *this / f2;
    Fraction::reduce();
    return *this;
}

// = OPERATOR
Fraction Fraction::operator=(Fraction f2)
{
    numerator = f2.numerator;
    denominator = f2.denominator;
    Fraction::reduce();
    return *this;
}



// post-increment operator
Fraction Fraction::operator++(int)
{
    Fraction tmp{*this};
    Fraction one(1, 1);
    *this += one;
    Fraction::reduce();
    tmp.reduce();
    return tmp;
}

// pre-increment operator
Fraction Fraction::operator++(void)
{
    Fraction one(1, 1);
    *this += one;
    Fraction::reduce();
    return *this;
}

// post-derement operator
Fraction Fraction::operator--(int)
{

    Fraction tmp{*this};
    Fraction one(1, 1);
    *this -= one;
    Fraction::reduce();
    tmp.reduce();
    return tmp;
}

// pre-decrement operator
Fraction Fraction::operator--(void) 
{
    Fraction one(1, 1);
    *this -= one;
    Fraction::reduce();
    return *this;
}

//   not operator
Fraction Fraction::operator~(void)
{
    Fraction tmp;
    tmp.numerator = denominator;
    tmp.denominator = numerator;
    tmp.reduce();
    return tmp;
}

// negative
Fraction Fraction::operator-(int)
{
    Fraction tmp;
    tmp.numerator = -numerator;
    tmp.denominator = denominator;
    tmp.reduce();
    return tmp;
}

// input and output operators
ostream &operator<<(ostream& out, const Fraction& fract)
{
    return out << fract.numerator << "/" << fract.denominator;
}

istream& operator>>(istream& in, Fraction& fract)
{
    int nume, denom;
    char slash;
    Fraction return_fract;
    
    if(in >> nume >> slash >> denom)
    {
        fract.numerator = nume;
        fract.denominator = denom;
        fract.reduce();
    }
    return in;
}




// Boolean operators
bool Fraction::operator!(void)
{
    return numerator==0;
}

bool Fraction::operator==(Fraction f2)
{
    return((float)numerator/denominator == (float)f2.numerator/f2.denominator);
}

bool Fraction::operator!=(Fraction f2) const
{
    return((float)numerator/denominator != (float)f2.numerator/f2.denominator);
}

bool Fraction::operator>=(Fraction f2)
{
    return((float)numerator/denominator >= (float)f2.numerator/f2.denominator);
}

bool Fraction::operator<=(Fraction f2)
{
    return((float)numerator/denominator <= (float)f2.numerator/f2.denominator);
}

bool Fraction::operator>(Fraction f2)
{
    return((float)numerator/denominator > (float)f2.numerator/f2.denominator);
}

bool Fraction::operator<(Fraction f2)
{
    return((float)numerator/denominator < (float)f2.numerator/f2.denominator);
}



//CASTING OPERATORS
Fraction::operator double(void)
{
    return (double)numerator/(double)denominator;
}

Fraction::operator float(void)
{
    return(float)numerator/(float)denominator;
}



//reduce function
void Fraction::reduce(void)
{
    int GCF = 1;
    for(int i=1 ; i <= numerator; i++)
    {
        if((numerator % i == 0) && (denominator % i == 0))
        {
            GCF = i;
        }
    }
    numerator/=GCF;
    denominator/=GCF;
}
