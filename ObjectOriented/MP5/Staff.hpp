#ifndef Staff_hpp
#define Staff_hpp


#include <stdio.h>
#include "MyDate.hpp"
#include "Person.hpp"
#include "Employee.hpp"

#include <iostream>
#include <string>

class Staff : public Employee
{
protected:
    string title;
public:
    Staff();
    Staff(const Staff& staff);
    Staff& operator = (const Staff& staff);
    virtual ~Staff();
    
    Staff(string _name, string _email, string _phone, MyDate _birthday, long _salary, MyDate _datehired, string _title);
    
    void PrintData();
    void InputData(); 
};


#endif /* Staff_hpp */
