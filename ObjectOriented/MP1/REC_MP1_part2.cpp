#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;


/*
 Ryan Corkill
 CPS 271
 March 1, 2022
 Machine Problem 1, Part 2
 */


//Create a struct to represent a student
struct Student
{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

//Read the information from the datafile to the array of students
int read_to_array(string path, Student students[])
{
    ifstream infile;
    infile.open(path);
    string first_name, last_name;
    int score, students_index = 0;

    //For each line (while infile.good()), collect the relevant information to assign to each student
    while( infile >> first_name >> last_name >> score && infile.good())
    {
        students[students_index].studentFName = first_name;
        students[students_index].studentLName = last_name;
        students[students_index].testScore = score;
        students_index += 1; //The student index allows us to keep track of the total number of students in the class
    }
    return (students_index-1);
}

//The get_grade function allows us to take a student's score and determine the associated grade
char get_grade(int score)
{
    score = floor(score/10);
    switch (score)
    {
        case 10: return 'A';
        case 9: return 'A';
        case 8: return 'B';
        case 7: return 'C';
        case 6: return 'D';
        default: return 'F';
    }
}

//This function, making use of the get_grade function, allows us to assign proper grades to each student
void assign_grades(int count, Student students[])
{
    for(int i = 0; i <= count; i++)
    {
        int score = students[i].testScore;
        char grade = get_grade(score);
        students[i].grade = grade;
    }
}

//This function tracks the highest score (and the index at which it occurs) for the class
int get_highest_score(int count, Student students[])
{
    int score_index = 0;
    int highest_score = 0;
    for(int i = 0; i <= count; i++)
    {
        int loop_score = students[i].testScore;
        if (loop_score > highest_score)
        {
            score_index = i; //i will equal the index of the highest scoring student
            highest_score = loop_score;
        }
    }
    return score_index;
}

//This function allows us to more cleanly determine the student with the highest score and print out their name and score
void print_student_with_highest_score(int count, Student students[])
{
    int score_index = get_highest_score(count, students);
    int highest_score = students[score_index].testScore;
    string highest_score_name = students[score_index].studentFName + " " + students[score_index].studentLName;
    cout << "\nThe student with the highest score is " + highest_score_name + " with a score of ";
    cout << highest_score << ".\nCongratulations, " << students[score_index].studentFName << "!\n" << endl;
}

//The print entire class function allows us to display the information for the whole class
void print_entire_class(int count, Student students[])
{
    cout << left << setw(30)<< "***** Class Information *****\n" << endl;
    for(int i = 0; i <= count; i++)
    {
        Student loop_student = students[i];
        cout << left << loop_student.studentLName << ", " << loop_student.studentFName << ", Test Score: " << loop_student.testScore << ", Grade: " << loop_student.grade << endl;
    }
}

int main()
{
    cout << "Ryan Corkill\nCPS 271\nMarch 1, 2022\nMachine Problem 1, Part 2\n\n";
    int max_class_size = 20; //We will set our maximum class size to 20
    Student students[max_class_size];
    
    int class_size = read_to_array("data1.txt", students); //We will fill on our student information
    assign_grades(class_size, students); //We will assign grades to each student
    print_entire_class(class_size, students); //Print the whole class
    print_student_with_highest_score(class_size, students); //Determine the highest score and provide a message stating the highest scoring student
}

