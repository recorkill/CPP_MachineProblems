#include "myQueue.hpp"
#include <iostream>



using namespace std;




void myQueue::enqueue(Customer person)
{
    //Print a message to the current minute's output whenever a customer arrives
    cout << "Customer number " << person.get_customer_number() << " has arrived. Adding to the queue." << endl;
    
    //Set the rear of the queue (back of the line) to the arriving customer
    rear = (rear + 1) % capacity;
    queue[rear] = person;
    
    count++;
}
    
    
void myQueue::dequeue()
{
    if (isEmpty()) //If the line is empty and dequeue is called, print this message (should never happen)
    {
        cout << "************************" << endl;
    }
    else
    {
        Customer person = queue[front];
        cout << "Customer number " << person.get_customer_number() << " has been served. Removing from the queue." << endl;
     
        front = (front + 1) % capacity; //Move the front of the line back one (the front of the line has been served, and is no longer in line)
        
        count--;
    }
}
