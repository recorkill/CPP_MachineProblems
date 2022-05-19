#ifndef cylinderType_hpp
#define cylinderType_hpp

#include <stdio.h>
#include "circleType.hpp"
//#include "pointType.hpp"
#include <iostream>

class cylinderType : public circleType
{
protected:
    double height;
    //circleType base;

public:
    cylinderType();
    //cylinderType(circleType circle, double height);
    cylinderType(double radius, pointType point, double height);
    
    double getVolume();
    double getSurfaceArea();
    double getHeight();
    //double getBaseRadius();
    //pointType getCenterpoint();
    
    void setHeight(double _height);
    //void setBaseRadius(double _base_radius);
    //void setCenterpoint(pointType point);
    //void setCenterpoint(int _x, int _y);
    
    void printCylinder();
    void inputCylinder();
    
};


#endif /* cylinderType_hpp */
