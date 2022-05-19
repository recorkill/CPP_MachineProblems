#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <string>
#include "MyDate.hpp"
#include "Person.hpp"
#include <string>

using namespace std;

class Student : public Person
{
protected:
    double GPA;
    enum gradelvl {FRESHMAN, SOPHOMORE, JUNIOR, SENIOR};
    
    gradelvl grade = FRESHMAN;
    
public:
    //Big four
    Student();
    Student(const Student& _student);
    Student& operator = (const Student& _student);
    virtual ~Student();
    
    Student(string _name, string _email, string _phone, MyDate _birthday, gradelvl _grade, double _GPA);
    
    void PrintData();
    void InputData();
    
    string StudentGrade(int grade);
};




#endif /* Student_hpp */
