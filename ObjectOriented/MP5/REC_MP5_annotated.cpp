#include <iostream>
#include "MyDate.hpp"
#include "Person.hpp"
#include "Employee.hpp"
#include "Faculty.hpp"
#include "Staff.hpp"
#include "Student.hpp"
#include <vector>
#include <iostream>
#include <string>

/*
 Write a menu driven main program which allows the user to enter in information for a Student, Faculty and Staff.  Objects of type Person and Employee are not allowed therefore they must be pure virtual classes.
 Finally, to demonstrate your knowledge of dynamic binding versus static binding, using either the List, Array or Vector container shown in Chapter 12 (Malik book), create an list/array/vector of pointers to Person which will allow you to dynamically create derived objects and store them. Once you put a handful of items in the list/array/vector, then loop thru it and print out the information for each object by using the Print() function.
 Similar to Homework 4, create an Inheritance Diagram which shows your class heirarchy and submit that as a image/scan/diagram.
 */

using namespace std;

int main()
{
    cout << "Ryan Corkill\nCPS 271\nMarch 9, 2022\nMachine Problem 5\n" << endl;
    vector <Person *> PeopleList; //Create a vector of people objects
    bool keep_going = true;
    while(keep_going == true) //Continue appending the list until the user specifies not to.
    {
        string entry;
        cout << "Would you like to enter information for a student, faculty, or staff? ";
        cin >> entry;
        cout << endl;
        if(entry == "student") //Based on the type of entry the user specifies, the correct InputData() fxn will be called, and the proper pointer will be created.
        {
            Student *student;
            student = new Student();
            student->InputData();
            PeopleList.push_back(student); //once the data is collected, the list is appended using the push_back() fxn
        }
        if(entry == "faculty") //The same sequence shown for student is repeated in the case of "faculty" or "staff" selection
        {
            Faculty *faculty;
            faculty = new Faculty();
            faculty->InputData();
            PeopleList.push_back(faculty);
        }
        if(entry == "staff")
        {
            
            Staff *staff;
            staff = new Staff();
            staff->InputData();
            PeopleList.push_back(staff);
        }
        
        //Prompt the user to either continue, or end the loop and view the entries
        cout << "\nTo add another entry, enter 1. Otherwise, enter any other key to print all entries.";
        cin >> keep_going;
        cout << endl << endl;
    }
    
    //PRINTING THE INFORMATION
    
    for(int i = 0; i < PeopleList.size(); i++) //for each item in the list of people, print their information
    {
        PeopleList[i]->PrintData(); //polymorphism: each object has its own "PrintData". determining which to call is done at run time!!!
    }
    
    cout << endl << endl << endl;
}
