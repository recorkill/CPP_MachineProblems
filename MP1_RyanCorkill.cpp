/*
 Machine Problem 1
 Ryan Corkill
 
 Purpose: This program will seek to take a user-given input, a length in centimenters, and performs various calculations on it. These calculations will include the areas of a square and circle, wherein the length is used as a side length and diameter, respectively. Additionally, the volume of a cube will be determined, once again using the input as a side length.
 
    Values will be converted to meters.
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    setprecision(4);
    
    // First, we will declare our variables
    float input_length_cm, input_length_m, pi;
    float circle_area, square_area, area_difference;
    
    int length_rounded_up, length_rounded_down; // We know that these numbers will be rounded, and thus will not need decimal points (i.e., integers).
    int cube_volume_rounded_up, cube_volume_rounded_down;
    
    
    // Next, we will ask the user to provide a length to perform calculations with
    cout << "CPS 171, Machine Problem 1\nGeometry Formulas by Ryan Corkill\nJanuary 18th, 2022" << endl << endl;
    cout << "Please input a length in centimeters as a floating-point number: ";
    cin >> input_length_cm;
    
    
    // Now we can perform calculations to assign values to our variables
    input_length_m = input_length_cm/100;
    pi = 3.14159;
    length_rounded_up = ceil(input_length_m);
    length_rounded_down = floor(input_length_m);
    circle_area = (pow((input_length_m/2), 2))*pi; 
    square_area = pow(input_length_m, 2);
    area_difference = square_area - circle_area;
    cube_volume_rounded_up = pow(length_rounded_up, 3);
    cube_volume_rounded_down = pow(length_rounded_down, 3);
    
    // Calculations are complete, and the values will now be echoed to the user
    cout << "The length provided is " << input_length_cm << " cm, equivalent to " << input_length_m << " m." << endl;
    cout << "The area of a square with this side length is " << square_area << " sq. m." << endl;
    cout << "The area of a circle with this diameter is " << circle_area << " sq. m." << endl;
    cout << "The difference in area between the square and circle is " << area_difference << " sq. m." << endl;
    cout << "When the length is rounded up, it creates a cube with volume " << cube_volume_rounded_up << " cu. m." << endl;
    cout << "When the length is rounded down, it creates a cube with volume " << cube_volume_rounded_down << " cu. m." << endl <<endl;
    
    
    // Now that the calculation is complete, the user will be prompted to use the Enter key to end the program
    cout << "Press the enter key to continue" << endl;
    cin.ignore();
    cin.get();
    
    
    
}
