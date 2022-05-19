#include "myArray.hpp"
#include <iostream>

using namespace std;

myArray::myArray() : start(0), end(0), size(0) {arr = new int[0];} ;

myArray::myArray(int _size) : start(0), end(_size), size(_size) {arr = new int[_size];} ;

myArray::myArray(int _start, int _end) : start(_start), end(_end) {size = (_end - _start); arr = new int[size];} ;

myArray::~myArray() {delete[]arr;} ;

void myArray::expand(void)
{
    int const_size = size;
    size*=2;
    int *tmparr = new int[size];
    for(int i=0; i<size; i++) {tmparr[i] = arr[i];}
    delete[] arr;
    arr = tmparr;
    myArray::initialize(const_size);
}

void myArray::initialize(int index_from)
{
    for(int i = index_from; i < size; i++) {arr[i] = 0;}
}


bool myArray::checkIndex(int index)
{
    bool in_range = true;
    if(index < start || index >= end)
    {
        in_range = false;
    }
    return in_range;
}

void myArray::add(int val)
{
    int pre_expand_size = size;
    myArray::expand();
    arr[pre_expand_size] = val;
}


int& myArray::operator[](int index)
{
    int adjusted_index = index - start;
    if
    return return_val;
}
