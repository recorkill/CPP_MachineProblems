#include <iostream>
#include <string>
#include <cmath>
#include "fraction.hpp"

using namespace std;

/*
Ryan Corkill
 CPS 271
 March 1, 2022
 Machine Problem 2
 */


//This function performs an operation between two fractions based on the specified operator
Fraction perform_operation(Fraction f1, Fraction f2, char op)
{
    Fraction return_fraction;
    switch (op)
    {
        case '+': return return_fraction.addFraction(f1, f2);
        case '-': return return_fraction.subtractFraction(f1, f2);
        case '/': return return_fraction.divideFraction(f1, f2);
        case '*': return return_fraction.multiplyFraction(f1, f2);
        default: return return_fraction;
    }
}

//This function provides a cleaner way of displaying the calculation summary
void describe_calc(Fraction f1, Fraction f2, Fraction calcd, char op)
{
    cout << "\nThe result of ";
    f1.Print();
    cout << " " << op << " ";
    f2.Print();
    cout << " is: ";
    calcd.Print();
}

//This function, continue loop, will remain true as long as the user does not enter q or Q (which ends the loop)
bool continue_loop(char keep_going)
{
    bool cont = true;
    if (keep_going == 'q')
    {
        cont = false;
    }
    if (keep_going == 'Q')
    {
        cont = false;
    }
    return cont;
}

int main()
{
    cout << "Ryan Corkill\nCPS 271\nMarch 1, 2022\nMachine Problem 2\n" << endl;
    
    //Declare the three fractions to be used (the first two are user-provided, the third is calculated)
    Fraction f1, f2, calculated_fraction;
    char keep_going = 'A'; //We know that we will always run the loop at least once, so we pick a non-q value
    while(continue_loop(keep_going) == true)
    {
        char op;
        cout << "Fraction 1\n***********\n";
        f1.Input(); //Get the first fraction
        cout << "\nFraction 2\n***********\n";
        f2.Input(); //Get the second fraction
        cout << "\nEnter an operator to be performed\n(+, -, /, *): ";
        cin >> op; //Get the operator
        calculated_fraction = perform_operation(f1, f2, op);
        describe_calc(f1, f2, calculated_fraction, op); //Create a summary of the calculation
        cout << "\n\nTo end this program, enter q or Q. To perform another calculation, enter any other letter." << endl;
        cin >> keep_going; //Allow the user to either continue or end the loop
        if(continue_loop(keep_going) == true)
        {
            cout << "\nYou have selected to continue.\n\n";
        }
        else{
            cout << "\nThis program will now end.\n";
        }
    }

}
