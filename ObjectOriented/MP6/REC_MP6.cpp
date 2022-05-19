#include <iostream>
#include "myArray.hpp"

using namespace std;

int main()
{
    myArray list(5);
    
    myArray mylist(2, 13);
    
    myArray yourlist(-5, 9);
    
    yourlist[4] = 13;
    
    for(int i = -5; i <=10; i++)
    {
        cout << "Index " << i << " Value: " << yourlist[i] << endl;
    }
}
