#include "Staff.hpp"
#include "Employee.hpp"
#include "MyDate.hpp"
#include "Person.hpp"

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

Staff::Staff() : title("") {};

Staff::~Staff() {}

Staff::Staff(string _name, string _email, string _phone, MyDate _birthday, long _salary, MyDate _datehired, string _title)
{
    name = _name;
    email = _email;
    phone = _phone;
    birthday = _birthday;
    salary = _salary;
    DateHired = _datehired;
    title = _title;
};

Staff::Staff(const Staff& staff)
{
    name = staff.name;
    email = staff.email;
    phone = staff.phone;
    birthday = staff.birthday;
    salary = staff.salary;
    DateHired = staff.DateHired;
    title = staff.title;
};

Staff& Staff::operator = (const Staff& staff)
{
    name = staff.name;
    email = staff.email;
    phone = staff.phone;
    birthday = staff.birthday;
    salary = staff.salary;
    DateHired = staff.DateHired;
    title = staff.title;
    return *this;
};

void Staff::InputData()
{
    cout << "Please enter the name of the staff, their email address, and phone number in the form\n(Name Email Phone): ";
    cin >> name >> email >> phone;
    cout <<"\nPlease enter the staff's birthdate in the space-separated form (month day year): ";
    birthday.InputData();
    cout << "\nPlease enter the staff's title and salary in the form (title salary): ";
    cin >> title >> salary;
    cout << "\nPlease enter the staff's date hired in the space-separated form (month day year): ";
    DateHired.InputData();
}


void Staff::PrintData()
{
    cout << "\n***********Staff***********\n";
    cout << setw(10) << "Name: " << setw(10) << title + " " + name << "     Birthday: ";
    birthday.PrintData();
    cout << "\n" << setw(10) << "Phone: " << setw(10) << phone << "        Email: " << email << endl;
    cout << setw(10) << " Salary: " << setw(10) << salary << "        Hired: ";
    DateHired.PrintData();
    cout << "\n***************************\n";
}
