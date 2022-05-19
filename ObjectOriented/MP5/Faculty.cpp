#include "Faculty.hpp"
#include "Staff.hpp"
#include "Employee.hpp"
#include "MyDate.hpp"
#include "Person.hpp"
#include <iomanip>

#include <iostream>
#include <string>

using namespace std;

Faculty::Faculty() : office(0), tenure(0), OfficeHours() {};

Faculty::~Faculty() {}

Faculty::Faculty(string _name, string _email, string _phone, MyDate _birthday, long _salary, MyDate _datehired, int _office, bool _tenure, MyDate _OfficeHours)
{
    name = _name;
    email = _email;
    phone = _phone;
    birthday = _birthday;
    salary = _salary;
    DateHired = _datehired;
    office = _office;
    tenure = _tenure;
    OfficeHours.push_back(_OfficeHours);
};

Faculty::Faculty(const Faculty& faculty)
{
    name = faculty.name;
    email = faculty.email;
    phone = faculty.phone;
    birthday = faculty.birthday;
    salary = faculty.salary;
    DateHired = faculty.DateHired;
    office = faculty.office;
    tenure = faculty.tenure;
    OfficeHours = faculty.OfficeHours;
};

Faculty& Faculty::operator = (const Faculty& faculty)
{
    name = faculty.name;
    email = faculty.email;
    phone = faculty.phone;
    birthday = faculty.birthday;
    salary = faculty.salary;
    DateHired = faculty.DateHired;
    office = faculty.office;
    tenure = faculty.tenure;
    OfficeHours = faculty.OfficeHours;
    return *this;
};

void Faculty::InputData()
{
    cout << "Please enter the name of the faculty, their email address, and phone number in the form\n(Name Email Phone): ";
    cin >> name >> email >> phone;
    cout <<"\nPlease enter the faculty's birthdate in the space-separated form (month day year): ";
    birthday.InputData();
    cout <<"\nPlease enter the faculty's hire date in the space-separated form (month day year): ";
    DateHired.InputData();
    cout << "\nPlease enter the faculty's office number and salary in the form (office# salary): ";
    cin >> office >> salary;
    cout << "\nIs the faculty tenured? Please enter 1 for yes, 0 for no: ";
    cin >> tenure;
    cout << "\nPlease enter a date the faculty holds office hours in form (month day year): ";
    MyDate input_day;
    input_day.InputData();
    OfficeHours.push_back(input_day);
}

void Faculty::PrintData()
{
    cout << "\n**********Faculty**********\n";
    cout << setw(10) << "Name: " << setw(10) << "Dr. " + name << "     Birthday: ";
    birthday.PrintData();
    cout << "\n" << setw(10) << "Phone: " << setw(10) << phone << "        Email: " << email << endl;
    cout << setw(10) << " Salary: " << setw(10) << salary << "        Hired: ";
    DateHired.PrintData();
    cout << "\n" << setw(10) << " Office#: " << setw(10) << office << "        Tenured: " << std::boolalpha << tenure << endl;
    cout << "Office hours: ";
    for (int i = 0; i < OfficeHours.size(); i++) {OfficeHours[i].PrintData();}
    cout << "\n***************************\n";
}
