#ifndef myArray_hpp
#define myArray_hpp

#include <stdio.h>

class myArray
{
private:
    int start;
    int end;
    int size;
    int *arr;
    
    void initialize(int index_from);
    void expand(void);
    
public:
    
    myArray();
    myArray(int _size);
    myArray(int _start, int _end);
    
    ~myArray();
    
    
    void add(int val);
    bool checkIndex(int index);
    
    int& operator[](int index);
    
    
};

#endif
