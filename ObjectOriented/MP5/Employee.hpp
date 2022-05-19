#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
#include "MyDate.hpp"
#include "Person.hpp"

#include <iostream>
#include <string>

class Employee : public Person
{
protected:
    
    long salary;
    MyDate DateHired;
    
public:
    //Big four
    Employee();
    Employee(const Employee& _employee);
    Employee& operator = (const Employee& _employee);
    virtual ~Employee();
    
    virtual void PrintData() = 0;
    virtual void InputData() = 0;
    
    
    
    
};
    
    
    
    

#endif /* Employee_hpp */
