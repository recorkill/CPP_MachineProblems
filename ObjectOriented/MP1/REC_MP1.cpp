#include <iostream>
#include <cmath>

using namespace std;

/*
 Ryan Corkill
 CPS 271
 March 1, 2022
 Machine Problem 1, Part 1
 */



//This function allows us to raise a number to a power
double power(double number, int power = 2)
{
    double return_val = pow(number, power);
    return return_val;
}

//This function allows us to convert the total time in hours, minutes, and seconds into total seconds
long hms_to_sec(int hr, int min, int sec)
{
    long total_sec = sec;
    total_sec += (min*60); //Add the minutes to the total
    total_sec += (hr*3600); //Add the hours to the total
    return total_sec;
}

//This function will allow us to test our hms_to_sec() fxn, looping until a negative hour value is given
void hms_check()
{
    int hours, minutes, seconds;
    cout << "Enter the number of hours: ";
    cin >> hours;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    cout << "Enter the number of seconds: ";
    cin >> seconds;
    if(hours < 0)
    {
        cout << "\nThe time returned is negative, therefore the loop will end.\n" << endl << endl;;
    }
    else
    {
        long total = hms_to_sec(hours, minutes, seconds);
        cout << "\nThe time entered is " << hours << ":" << minutes << ":" << seconds << ", equal to " << total << " total seconds. You will now be prompted to enter a new time. Enter a negative hour value to end the loop.\n" << endl;
        hms_check();
    }
}

//The swap function allows us to swap two values
//CORRECTED AS PER FEEDBACK RECIEVED
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

//This function will allow us to demonstrate the swap function more cleanly in main()
//CHANGED PER CORRECTIONS MADE TO SWAP FXN
void swap_check(int A, int B)
{
    cout << "Initially, variable A = " << A << " and variable B = " << B << endl;
    swap(A, B);
    cout << "After Swapping, variable A = " << A << " and variable B = " << B << endl << endl;
}

int main()
{
    cout << "Ryan Corkill\nCPS 271\nMarch 1, 2022\nMachine Problem 1, Part 1\n\n";
    
    // Testing power()
    double number;
    int pwr;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter a power to raise the number to: ";
    cin >> pwr;
    double value = power(number, pwr);
    cout << "Raising " << number << " to the power of " << pwr << " yields " << value << endl << endl;
    
    

    // Testing hms_to_sec()
    hms_check();

    
    // Testing swap()
    int A, B;
    cout << "Enter an integer to assign to variable A: ";
    cin >> A;
    cout << "Enter an integer to assign to variable B: ";
    cin >> B;
    swap_check(A, B);
}

