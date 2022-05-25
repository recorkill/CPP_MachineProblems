#ifndef Complex_h
#define Complex_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//CODE PROVIDED TO WORK OFF OF

class Complex
{
    friend ostream& operator<<(ostream& out, const Complex& theComplex)
    {
        if(theComplex.getImaginary() >= 0)
        {
            out << theComplex.getReal() << "+" << theComplex.getImaginary() << "i"; return out;
        }
        
        // In case the imaginary component is negative, we don't want to see "+-"
        else if(theComplex.getImaginary() < 0)
        {
            out << theComplex.getReal() << theComplex.getImaginary() << "i"; return out;
        }
        
        else
            return out;
    };
    
    friend istream& operator>>(istream& in, Complex& theComplex)
    {
        double im, re;
        if(in >> im >> re)
        {
            theComplex.setReal(re);
            theComplex.setImaginary(im);
        }
        return in;
    };
    
    friend Complex operator+(const Complex& lhs, const Complex& rhs)
    {
        Complex new_complex;
        new_complex.setReal(lhs.getReal() + rhs.getReal());
        new_complex.setImaginary(lhs.getImaginary() + rhs.getImaginary());
        
        return new_complex;
    };
    
    friend Complex operator-(const Complex& lhs, const Complex& rhs)
    {
        Complex new_complex;
        new_complex.setReal(lhs.getReal() - rhs.getReal());
        new_complex.setImaginary(lhs.getImaginary() - rhs.getImaginary());
        
        return new_complex;
    };
    
    //(a + bi)(c + di) = (ac - bd) + (b - d)i
    friend Complex operator*(const Complex& lhs, const Complex& rhs)
    {
        Complex new_complex;
        
        double ac = lhs.getReal()*rhs.getReal();
        double bd = lhs.getImaginary()*rhs.getImaginary();
        
        new_complex.setReal(ac - bd);
        new_complex.setImaginary(lhs.getImaginary() - rhs.getImaginary());
        
        return new_complex;
    };
    
    // (a+bi)/(c+di) = [(ac+bd)/(c2 + d2)] + [(bc-ad)/(c2+d2)]i
    friend Complex operator/(const Complex& lhs, const Complex& rhs)
    {
        Complex new_complex;
        double C2plusD2, ACplusBD, BCminusAD;
        double a, b, c, d;
        a = lhs.getReal();
        b = lhs.getImaginary();
        c = rhs.getReal();
        d = rhs.getImaginary();
        
        C2plusD2 = (c*c)+(d*d);
        ACplusBD = (a*c)+(b*d);
        BCminusAD = (b*c)-(a*d);
        
        new_complex.setReal(ACplusBD / C2plusD2);
        new_complex.setImaginary(BCminusAD / C2plusD2);
        
        return new_complex;
    };
    
public:
    Complex(double re = 0.0, double im = 0.0) : real(re), imag(im) {};
    double getReal(void) const {return real;};          // return real part
    double getImaginary(void) const {return imag;};     // return imaginary part
    void setReal(double re) {real = re;};               // sets the real part
    void setImaginary(double im) {imag = im;};          // sets the imaginary part
    void convertStringToComplex(const string& complexString)
    {
        string re, im, entry = complexString;
        int location = entry.find('+');

        if(location == string::npos)
        {cout << "The string entered could not be converted to a complex number.\n"; return;}
        
        re = entry.substr(0, location);
        im = entry.substr(location+1, entry.size());
        im.pop_back(); //remove the i from the imaginary number string
        
        //cout << "Real: " << re << "   Imag: " << im << endl;
        
        real = stod(re);
        imag = stod(im);
        
    };
private:
    double real;
    double imag;
};



#endif /* Complex_h */
