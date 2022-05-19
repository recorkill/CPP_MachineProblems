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



// input and output operators
ostream &operator<<(ostream& out, const Fraction& fract)
{
    return out << fract.numerator << "/" << fract.denominator;
}

istream& operator>>(istream& in, Fraction& fract)
{
    int nume, denom;
    Fraction return_fract;
    
    if(in >> nume >> denom)
    {
        fract.numerator = nume;
        fract.denominator = denom;
        fract.reduce();
    }
    return in;
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


bool Fraction::operator>(Fraction f2)
{
    return((float)numerator/denominator > (float)f2.numerator/f2.denominator);
}

bool Fraction::operator<(Fraction f2)
{
    return((float)numerator/denominator < (float)f2.numerator/f2.denominator);
}


bool Fraction::operator==(Fraction f2)
{
    return((float)numerator/denominator == (float)f2.numerator/f2.denominator);
}
