#ifndef circleType_hpp
#define circleType_hpp

#include <stdio.h>
#include "pointType.hpp"
#include <iostream>
#include "pointType.hpp"

class circleType
{
protected:
    double radius;
    pointType centerpoint;

public:
    circleType();
    circleType(double rad, pointType point);
    
    void setRadius(double rad);
    void setCenterpoint(pointType point);
    void setCenterpoint(int _x , int _y);

    
    double getRadius();
    pointType getCenterpoint();
    
    double getArea();
    double getCircumference();
    
    void printCircle();
    void inputCircle();
};


#endif /* circleType_hpp */
