#include <iostream>
#include <stdlib.h>
#include "myQueue.hpp"
#include "customer.hpp"



using namespace std;

int main()
{
    cout << "Ryan Corkill\nCPS 272\nApril 13th, 2022\nMachine Problem 2, Queues" << endl << endl;
    
    //A customer will arrive at the restaurant and enter the line in one to four minutes
    //Once the arriving customer arrives in line, the next customer begins travelling to the restaurant (also takes between 1 and 4 minutes)
    
    //The customer at the beginning of the line will be served every one to four minutes
    //Once that customer is served, the next customer will be served in the next one to four minutes
    
    
    int total_min = 120; //We will run the simulation for a total of 120 minutes
    int current_min = 0; //Initiailly, we start at minute zero
    
    myQueue line; //Create a myQueue object to represent the line of customers
    
    Customer arriving_customer(0, 1); //Customer 1 will be arriving to the line at minute 0
    
    int customer_number = 1;
    int service_min = arriving_customer.get_service_time(); //represents the random value between 1 and 4 that the next customer in line will wait to be served
    
    while(current_min <= total_min)
    {
        cout << "Minute " << current_min << ": \n"; //Print out a message for each minute (whatever happens during this minute such as arrivals and departures will be noted)
 
        int arrival_time = arriving_customer.get_arrival_time();
        
        //Once the current minute equals the arrival time of the arriving customer, they enter the line
        if(current_min == arrival_time)
        {
            customer_number++;
            
            line.enqueue(arriving_customer); //Add the arriving (now arrived) customer to the line
            
            //Create a customer object for the following customer
            Customer nextCustomer(current_min, customer_number);
            
            //Set the Customer object representing the arriving customer to this new customer
            arriving_customer.set_customer(nextCustomer);
        }
        
        if(current_min == service_min) //CUSTOMER IS BEING SERVED, LEAVES THE LINE
        {
            //cout << "Customer number " << line.peek().get_customer_number() << " has been served, and is now leaving the line (being dequeued).";
            
            if(!line.isEmpty()) {line.dequeue();} //Remove from the line
            
            service_min = current_min + 4;
            //service_min = current_min + rand() % 4 + 1; //Assign a new service minute between 1 and 4 minutes from the current time
        }
        
        current_min ++ ; 
        
        cout << "*****" << endl;

    }
    
    line.print();
    
    
    
    
    
}
