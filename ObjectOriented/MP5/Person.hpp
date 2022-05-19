#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "MyDate.hpp"

using namespace std;

class Person
{
protected:
    string name = "";
    string phone = "";
    string email = "";
    MyDate birthday;
    
public:
    //Big four
    Person();
    Person(const Person& _person);
    Person& operator = (const Person& person);
    virtual ~Person();
    
    Person(string name, string phone, string email, MyDate birthday);
    
    virtual void PrintData() = 0;
    virtual void InputData() = 0;
    
};



#endif /* Person_hpp */
