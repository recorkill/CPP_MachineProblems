#ifndef Faculty_hpp
#define Faculty_hpp

#include <stdio.h>
#include "MyDate.hpp"
#include "Person.hpp"
#include "Employee.hpp"
#include <vector>

#include <iostream>
#include <string>

using namespace std;


class Faculty : public Employee
{
protected:
    int office;
    bool tenure;
    vector<MyDate> OfficeHours;
public:
    Faculty();
    Faculty(const Faculty& faculty);
    Faculty& operator = (const Faculty& faculty);
    virtual ~Faculty();
    
    Faculty(string _name, string _email, string _phone, MyDate _birthday, long _salary, MyDate _datehired, int _office, bool _tenure, MyDate _OfficeHours);
    
    void PrintData();
    void InputData();
};


#endif /* Faculty_hpp */
