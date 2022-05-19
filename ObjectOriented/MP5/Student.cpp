#include "Student.hpp"
#include "MyDate.hpp"
#include "Person.hpp"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;



Student::Student() : GPA(0.0), grade(FRESHMAN) {}; //Empty constructor

Student::~Student() {}

Student::Student(const Student& _student) //Copy constructor
{
    name = _student.name;
    email = _student.email;
    phone = _student.phone;
    birthday = _student.birthday;
    grade = _student.grade;
    GPA = _student.GPA;
};

Student& Student::operator = (const Student& _student)
{
    name = _student.name;
    email = _student.email;
    phone = _student.phone;
    birthday = _student.birthday;
    grade = _student.grade;
    GPA = _student.GPA;
    return *this;
}

Student::Student(string _name, string _email, string _phone, MyDate _birthday, gradelvl _grade, double _GPA)
{
    name = _name;
    email = _email;
    phone = _phone;
    birthday = _birthday;
    grade = _grade;
    GPA = _GPA;
};


string Student::StudentGrade(int grade)
{
    switch (grade)
    {
        case 0 : return "Freshman";
        case 1: return "Sophomore";
        case 2: return "Junior";
        case 3: return "Senior";
        default: return "error";
    }
}

void Student::InputData()
{
    int grade_entry;
    cout << "Please enter the name of the student, their email address, and phone number in the form (Name Email Phone): ";
    cin >> name >> email >> phone;
    cout <<"\nPlease enter the student's birthdate in the space-separated form (month day year): ";
    birthday.InputData();
    cout << "\nPlease enter the students grade level (0 for freshman, 3 for senior) and GPA: ";
    cin >> grade_entry >> GPA;
    grade = gradelvl(grade_entry);
}

void Student::PrintData()
{
    cout << "\n**********Student**********\n";
    cout << setw(10) << "Name: " << setw(10) <<  name << "     Birthday: ";
    birthday.PrintData();
    cout << "\n" << setw(10) << "Phone: " << setw(10) << phone << "        Email: " << email << endl;
    cout << setw(10) << "Grade: " << setw(10) << Student::StudentGrade(grade) << "          GPA: " << GPA;
    cout << "\n***************************\n";
}
