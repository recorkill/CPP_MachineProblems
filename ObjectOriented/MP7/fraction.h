#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

template <class T>
class Fraction
{
    T numerator;
    T denominator;
    
public:
    
    void Print();
    void Input();
    
    Fraction() : numerator(0), denominator(1) {};
    Fraction(T nume) : numerator(nume), denominator(1) {};
    Fraction(T nume, T denom)
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
    };
    
    
    //BINARY OPERATORS
    Fraction operator+(Fraction f2)
    {
        Fraction fract((numerator*f2.denominator)+(denominator*f2.numerator), (denominator*f2.denominator));
        return fract;
    };
    
    Fraction operator-(Fraction f2)
    {
        Fraction fract((numerator*f2.denominator)-(denominator*f2.numerator), (denominator*f2.denominator));
        return fract;
    };
    
    Fraction operator=(Fraction f2)
    {
        numerator = f2.numerator;
        denominator = f2.denominator;
        return *this;
    };
    
    Fraction operator/(Fraction f2)
    {
        Fraction fract((numerator*f2.denominator), (denominator*f2.numerator));
        return fract;
    };
    
    Fraction operator*(Fraction f2)
    {
        Fraction fract((numerator*f2.numerator), (denominator*f2.denominator));
        return fract;
    };
    
    Fraction &operator+=(Fraction f2) {*this = *this + f2; return *this;};
    Fraction &operator-=(Fraction f2) {*this = *this - f2; return *this;};
    Fraction &operator/=(Fraction f2) {*this = *this / f2; return *this;};
    Fraction &operator*=(Fraction f2) {*this = *this * f2; return *this;};
    
    //UNARY OPERATORS
    Fraction operator++(void)
    {
        Fraction one(1, 1);
        *this += one;
        return *this;
    };
    
    Fraction operator++(int)
    {
        Fraction tmp{*this};
        Fraction one(1, 1);
        *this += one;
        return tmp;
    };
    
    Fraction operator--(void)
    {
        Fraction one(1, 1);
        *this -= one;
        return *this;
    };
    
    Fraction operator--(int)
    {
        Fraction tmp{*this};
        Fraction one(1, 1);
        *this -= one;
        return tmp;
    };
    
    Fraction operator~(void)
    {
        Fraction tmp;
        tmp.numerator = denominator;
        tmp.denominator = numerator;
        return tmp;
    };
    
    Fraction operator-(int)
    {
        Fraction tmp;
        tmp.numerator = -numerator;
        tmp.denominator = denominator;
        return tmp;
    };
    
    // IN/OUT OPERATORS
    friend ostream& operator<<(ostream& out, const Fraction& fract)
    {return out << fract.numerator << "/" << fract.denominator;};
    
    friend istream& operator>>(istream& in, Fraction& fract)
    {
        T nume, denom;
        char slash;
        Fraction return_fract;
        
        if(in >> nume >> slash >> denom)
        {
            fract.numerator = nume;
            fract.denominator = denom;
        }
        return in;
    };

    // BOOLEAN OPERATORS
    bool operator>(Fraction f2)
    {return((float)numerator/denominator > (float)f2.numerator/f2.denominator);};
    
    bool operator>=(Fraction f2)
    {return((float)numerator/denominator >= (float)f2.numerator/f2.denominator);};
    
    bool operator<(Fraction f2)
    {return((float)numerator/denominator < (float)f2.numerator/f2.denominator);};
    
    bool operator<=(Fraction f2)
    {return((float)numerator/denominator <= (float)f2.numerator/f2.denominator);};
    
    bool operator==(Fraction f2)
    {return((float)numerator/denominator == (float)f2.numerator/f2.denominator);};
    
    bool operator!=(Fraction f2) const
    {return((float)numerator/denominator != (float)f2.numerator/f2.denominator);};
    
    bool operator!(void) {return numerator==0;};


};

