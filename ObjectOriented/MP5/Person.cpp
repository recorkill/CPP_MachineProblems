#include "Person.hpp"
#include <string>
#include <iostream>
#include "MyDate.hpp"

using namespace std;

Person::Person() : name(""), phone(""), email("") {birthday = MyDate();} ; //Empty constructor
Person::Person(const Person& _person) : name(_person.name), phone(_person.phone), email(_person.email), birthday(_person.birthday) {}; //Copy construct
Person::Person(string name, string phone, string email, MyDate birthday) : name(name), phone(phone), email(email), birthday(birthday) {};

Person::~Person() {}

void Person::InputData()
{
    cout << "Please enter the name of the person, their email address, and phone number in the form\n(Name Email Phone): ";
    cin >> name >> email >> phone;
    cout <<"\nPlease enter the person's birthdate in the space-separated form (year month day): ";
    birthday.InputData();
}

void Person::PrintData()
{
    cout << "\n*****Personal Information*****\nName: " << name << " email: " << email;
    cout<< "\nphone number: " << phone << " birthday: ";
    birthday.PrintData();
}

Person& Person::operator = (const Person& _person) {name = _person.name; email = _person.email; phone = _person.phone; birthday = _person.birthday; return *this;}

