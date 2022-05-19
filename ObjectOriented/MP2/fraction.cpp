#include "fraction.hpp"
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1; //The default constructor initializes a fraction zero, so the choice of a non-zero denominator is arbitrary
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
    numerator = nume;
    denominator = denom;
}


void Fraction::Print()
{
    cout << numerator << "/" << denominator;
}


void Fraction::Input()
{
    cout << "Enter a new numerator value: ";
    cin >> numerator;
    cout << "Enter a new denominator value: ";
    cin >> denominator;
    //ERROR HANDLING
    //The error we need to accommodate for is division by zero. This while loop handles the user entering a denominator value of 0
    while(denominator == 0)
    {
        cout << "\nINVALID ENTERY --- the denominator cannot equal zero.\nPlease enter a non-zero value for the denominator: ";
        cin >> denominator;
    }
    
}

Fraction Fraction::addFraction(Fraction to_be_added)
{
    int nume = to_be_added.numerator;
    int denom = to_be_added.denominator;
    int return_nume = (numerator*denom) + (nume*denominator);
    int return_denom = denom*denominator;
    Fraction return_fract;
    return_fract.numerator = return_nume;
    return_fract.denominator = return_denom;
    return return_fract;
}

Fraction Fraction::addFraction(Fraction fract1, Fraction fract2)
{
    int nume1, nume2, denom1, denom2, return_nume, return_denom;
    nume1 = fract1.numerator;
    nume2 = fract2.numerator;
    denom1 = fract1.denominator;
    denom2 = fract2.denominator;
    return_nume = (nume1*denom2) + (nume2*denom1);
    return_denom = denom1*denom2;
    Fraction return_fract;
    
    //UPDATE CURRENT OBJECT
    numerator = return_nume;
    denominator = return_denom;
    
    return_fract.numerator = return_nume;
    return_fract.denominator = return_denom;
    return return_fract;
}


Fraction Fraction::subtractFraction(Fraction to_be_subtracted)
{
    int nume = to_be_subtracted.numerator;
    int denom = to_be_subtracted.denominator;
    int return_nume = (numerator*denom) - (nume*denominator);
    int return_denom = denom*denominator;
    Fraction return_fract;
    return_fract.numerator = return_nume;
    return_fract.denominator = return_denom;
    return return_fract;
}

Fraction Fraction::subtractFraction(Fraction fract1, Fraction fract2)
{
    int nume1, nume2, denom1, denom2, return_nume, return_denom;
    nume1 = fract1.numerator;
    nume2 = fract2.numerator;
    denom1 = fract1.denominator;
    denom2 = fract2.denominator;
    return_nume = (nume1*denom2) - (nume2*denom1);
    return_denom = denom1*denom2;
    Fraction return_fract;
    
    //UPDATE CURRENT OBJECT
    numerator = return_nume;
    denominator = return_denom;
    
    return_fract.numerator = return_nume;
    return_fract.denominator = return_denom;
    return return_fract;
}



Fraction Fraction::multiplyFraction(Fraction to_be_multiplied)
{
    int nume = to_be_multiplied.numerator;
    int denom = to_be_multiplied.denominator;
    int return_nume = numerator*nume;
    int return_denom = denom*denominator;
    Fraction return_fract;
    return_fract.numerator = return_nume;
    return_fract.denominator = return_denom;
    return return_fract;
}

Fraction Fraction::multiplyFraction(Fraction fract1, Fraction fract2)
{
    int nume1, nume2, denom1, denom2, return_nume, return_denom;
    nume1 = fract1.numerator;
    nume2 = fract2.numerator;
    denom1 = fract1.denominator;
    denom2 = fract2.denominator;
    return_nume = nume1*nume2;
    return_denom = denom1*denom2;
    Fraction return_fract;
    
    //UPDATE CURRENT OBJECT
    numerator = return_nume;
    denominator = return_denom;
    
    return_fract.numerator = return_nume;
    return_fract.denominator = return_denom;
    return return_fract;
}

Fraction Fraction::divideFraction(Fraction to_be_divided)
{
    int nume = to_be_divided.numerator;
    int denom = to_be_divided.denominator;
    int return_nume = numerator*denom;
    int return_denom = denominator*nume;
    Fraction return_fract;
    return_fract.numerator = return_nume;
    return_fract.denominator = return_denom;
    return return_fract;
}

Fraction Fraction::divideFraction(Fraction fract1, Fraction fract2)
{
    int nume1, nume2, denom1, denom2, return_nume, return_denom;
    nume1 = fract1.numerator;
    nume2 = fract2.numerator;
    denom1 = fract1.denominator;
    denom2 = fract2.denominator;
    return_nume = nume1*denom2;
    return_denom = denom1*nume2;
    Fraction return_fract;
    
    //UPDATE CURRENT OBJECT
    numerator = return_nume;
    denominator = return_denom;
    
    return_fract.numerator = return_nume;
    return_fract.denominator = return_denom;
    return return_fract;
}
