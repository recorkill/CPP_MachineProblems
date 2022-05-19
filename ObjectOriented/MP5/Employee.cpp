#include "Employee.hpp"
#include "MyDate.hpp"
#include "Person.hpp"

#include <iostream>
#include <string>

using namespace std;

Employee::Employee() // Empty operator
{
    salary = 0;
    name = "";
    phone = "";
    email = "";
    birthday = MyDate();
    DateHired = MyDate();
};

Employee::Employee(const Employee& employee)  //Copy operator
{
    salary = employee.salary;
    name = employee.name;
    phone = employee.phone;
    email = employee.email;
    birthday = employee.birthday;
    DateHired = employee.DateHired;
};

Employee& Employee::operator = (const Employee& employee)  //
{
    salary = employee.salary;
    name = employee.name;
    phone = employee.phone;
    email = employee.email;
    birthday = employee.birthday;
    DateHired =employee.DateHired;
    return *this;
}

Employee::~Employee() {}

void Employee::InputData()
{
    cout << "Please enter the employee's salary: ";
    cin >> salary;
    cout <<"\nPlease enter the employee's hire date in the space-separated form (year month day): ";
    DateHired.InputData();
}

void Employee::PrintData()
{
    cout << "\nThe employee's salary is " << salary << " and their date hired is: ";
    DateHired.PrintData();
}
