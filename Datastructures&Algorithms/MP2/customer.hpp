#ifndef customer_hpp
#define customer_hpp


#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class Customer
{
    int service_time;
    int arrival_time;
    
    int customer_number;
public:
    
    Customer(int time, int customer_num)
    {
        //arrival_time = rand() % 4 + 1 + time;
        arrival_time = 1 + time;
        //service_time = rand() % 4 + 1 + arrival_time;
        service_time = 4 + arrival_time;
        customer_number = customer_num;
    };
    
    Customer()
    {
        //arrival_time = rand() % 4 + 1;
        arrival_time = 1;
        //service_time = rand() % 4 + 1 + arrival_time;
        service_time = 4 + arrival_time;
        customer_number = 1;
    };
    
    int get_service_time() {return service_time;};
    int get_arrival_time() {return arrival_time;};
    int get_customer_number() {return customer_number;};
    
    void set_customer(Customer _customer)
    {
        arrival_time = _customer.arrival_time;
        service_time = _customer.service_time;
        customer_number = _customer.customer_number;
    };
    
    void print_customer() //for debugging
    {
        std::cout << "\n###Customer " << customer_number << ": arrive min: " << arrival_time << " service min: " << service_time << std::endl;
    }

};
    

#endif /* customer_hpp */
