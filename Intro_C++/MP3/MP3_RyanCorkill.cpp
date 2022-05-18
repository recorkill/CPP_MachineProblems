//
//  main.cpp
//  MP3
//
//  Created by Ryan on 1/19/22.
//

#include <iostream>
using namespace std;

int main()
{
    cout << "MP3, Maximizing Profit by Ryan Corkill\nJanuary 31, 2022" << endl << endl;
    
    //We start by declaring the variables we will take as user-given inputs
    int units_occupied, rent, maintenance, increase_for_vacancy;
    
    
    //The user is prompted to enter the parameters of the appartment complex they would like to optimize
    cout << "Please enter the total number of units: ";
    cin >> units_occupied;
    cout << "Please enter the minimum rent to fill all units: $";
    cin >> rent;
    cout << "Please enter the maintenance cost for an occupied unit: $";
    cin >> maintenance;
    cout << "Please enter the increase to rent that causes a vacancy: $";
    cin >> increase_for_vacancy;
    

    //Seperate values, representing the maximum values of each of these parameters, are declared
    int max_rent, max_units_occupied, max_revenue = units_occupied*(rent-maintenance);
    
    
    /*
     We will initialize a value for "loop_revenue", which will serve as the value to compare our max reveune to in the following while-loop.
     
    As loop_reveune increases, the max_revenue is updated to that value. Once the loop_revenue begins to decrease (which happens at the point following the true maximum revenue), the loop ends with max_revenue equal to the point before (the true maximum).
     */
    
    int loop_revenue = max_revenue;
    while(loop_revenue >= max_revenue)
    {
        rent += increase_for_vacancy;
        units_occupied -= 1;
        loop_revenue = units_occupied*(rent-maintenance);
        
        //This if statement updates max_revenue to equal loop_revenue as long as loop_revenue continues to increase (once it stops increasing, the true maximum revenue has been reached).
        //Once the true maximum revenue is met, the condition will not be satisfied and the while loop will end.
        if (loop_revenue >= max_revenue)
        {
            max_revenue = loop_revenue;
            max_rent = rent;
            max_units_occupied = units_occupied;
        }
    }
    
    cout << "\nThe most profitable number of units to rent is: " << max_units_occupied << endl;
    cout << "The maximum profit is: $" << max_revenue << endl << endl;

}
