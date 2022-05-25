#ifndef myQueue_hpp
#define myQueue_hpp

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "customer.hpp"

#define MAX 1000


class myQueue
{
    int front, rear, count, capacity;
    
    Customer *queue;
    
public:
    
    myQueue(int size = MAX) : front(0), rear(-1), count(0), capacity(size) {queue = new Customer[size];};
    
    ~myQueue() {delete[] queue;};
    
    void enqueue(Customer person);
    void dequeue();
    
    bool isEmpty() {return (count==0);};
    bool isFull() {return (count == capacity);};
    
    Customer peek() {return queue[front];};
    
    void print() {std::cout << "count: " << count << std::endl;};
    
    
    
};









#endif /* myQueue_hpp */








