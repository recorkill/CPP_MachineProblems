#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include "fraction.hpp"

using namespace std;
/*
//This function, continue loop, will remain true as long as the user does not enter q or Q (which ends the loop)
bool continue_loop(char keep_going)
{
    bool cont = true;
    if (keep_going == 'q') cont = false;
    if (keep_going == 'Q') cont = false;
    return cont;
}

//If a binary operation is selected, this function can be claled to perform the proper calculation
void Binary_calcs(Fraction f1, Fraction f2, string op)
{
    if      (op == "+") cout << f1+f2;
    else if (op == "-")  cout << f1-f2;
    else if (op == "*")  cout << f1*f2;
    else if (op == "/")  cout << f1/f2;
    else if (op == "+=")  cout << (f1 += f2);
    else if (op == "-=")  cout << (f1 -= f2);
    else if (op == "*=")  cout << (f1 *= f2);
    else if (op == "/=")  cout << (f1 /= f2);
    else if (op == "=")  cout << (f1 = f2);
    
    else if (op == ">")  std::cout << std::boolalpha << (f1>f2);
    else if (op == "<")  std::cout << std::boolalpha << (f1<f2);
    else if (op == ">=")  std::cout << std::boolalpha << (f1>=f2);
    else if (op == "<=")  std::cout << std::boolalpha << (f1<=f2);
    else if (op == "==")  std::cout << std::boolalpha << (f1==f2);
    else if (op == "!=")  std::cout << std::boolalpha << (f1!=f2);
}

//If a unary prefix operation is selected, this function can be claled to perform the proper calculation
void UnaryPrefix_calcs(Fraction f1, string op)
{
    Fraction minus(-1, 1);
    if      (op == "~") cout << ~f1;
    else if (op == "-")  cout << (f1*minus);
    else if (op == "!")  std::cout << std::boolalpha << (!f1);
    else if (op == "--")  cout << --f1;
    else if (op == "++")  cout << ++f1;
    else if (op == "double")  cout << (double) f1;
    else if (op == "float")  cout << (float) f1;
}

//If a unary postfix operation is selected, this function can be claled to perform the proper calculation
void UnaryPostfix_calcs(Fraction f1, string op)
{
    if      (op == "++") cout << f1++;
    else if (op == "--")  cout << f1--;
}

int main()
{
    
    cout << "Ryan Corkill\nCPS 271\nMarch 4, 2022\nMachine Problem 3\n" << endl;
    cout << "Welcome to the fraction calculator.";
    char keep_going = 'A'; //We know that we will always run the loop at least once

    
    while(continue_loop(keep_going) == true)
    {
        Fraction f1, f2, f3;
        string op, op_type;
        cout << "\n\nPlease specify the type of operation you would like to do\n('UnaryPrefix', 'UnaryPostfix', or 'Binary'): ";
        cin >> op_type; //Get the operation type
        
        //BINARY EQS
        if(op_type == "Binary")
        {
            cout << "\nNote: please ensure all fractions and operators are space-separated.\n";
            cout << "Enter an equation (e.g. 1/2 + 3/2): ";
            //If the operation is binary, we can expect to recieve our fractions and operation in this order
            cin >> f1 >> op >> f2;
            cout << f1 << " " << op << " " << f2 << " is ";
            Binary_calcs(f1, f2, op);
        }
        
        //UNARYPREFIX EQS
        else if(op_type == "UnaryPrefix")
        {
            cout << "\nNote: please ensure all fractions and operators are space-separated.\n";
            cout << "Enter an equation (e.g. ++ 1/2): ";
            //If the operation is unary prefix, we can expect to recieve our fraction and operation in this order
            cin >> op >> f1;
            cout << op << f1 << " is ";
            UnaryPrefix_calcs(f1, op);
        }
        
        //UNARYPOSTFIX EQS
        else if(op_type == "UnaryPostfix")
        {
            cout << "\nNote: please ensure all fractions and operators are space-separated.\n";
            cout << "Enter an equation (e.g. 1/2 --): ";
            //If the operation is unary postfix, we can expect to recieve our fraction and operation in this order
            cin >> f1 >> op;
            cout << f1 << op << " is ";
            UnaryPostfix_calcs(f1, op);
        }
        
        //This handles the case of one of the three operation types not being properly specified.
        else
        {
            cout << "\nInvalid entry. Please try again using one of the keywords. The possible keywords are:" << endl;
            cout << "'Binary' (+, -, /, *, +=, -=, *=, /=, ==, >=, <=, <, >, !=)" << endl;
            cout << "'UnaryPrefix' (++, --, -, ~, !, double, float)" << endl;
            cout << "'UnaryPostfix' (++, --)" << endl;
             //We also describe to the user all possible operations, and the keyword they fall under in case of confusion
        }
        
        cout << "\n\nTo end this program, enter q or Q. To perform another calculation, enter any other letter." << endl;
        cin >> keep_going; //Allow the user to either continue or end the loop
        if(continue_loop(keep_going) == true)
        {
            cout << "\nYou have selected to continue.\n";
        }
        else
        {
            cout << "\nThis program will now end.\n";
        }
    }
*/
    
    
    
int main()
{
    Fraction fract;
    cout << "enter fract: ";
    cin >> fract;
}

