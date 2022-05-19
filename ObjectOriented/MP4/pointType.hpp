#ifndef pointType_hpp
#define pointType_hpp

#include <stdio.h>

class pointType
{
protected:
    
    int x;
    int y;

public:
    pointType();
    pointType(int _x, int _y);
    
    void setPoint(int _x, int _y);
    
    int getx();
    int gety();
    
    void inputPoint();
    void printPoint();
};


#endif /* pointType_hpp */
