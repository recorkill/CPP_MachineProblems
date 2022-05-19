#include "cylinderType.hpp"
#include "pointType.hpp"
#include <cmath>
#include "circleType.hpp"
#include <iostream>

using namespace std;

cylinderType::cylinderType()
{
    radius = 0.0;
    height = 0.0;
    centerpoint = pointType(); //added
}

cylinderType::cylinderType(double _radius, pointType point, double _height) //Building cylinder with a circle
{

    radius = _radius; //added
    centerpoint = point; //added
    height = _height;
}

double cylinderType::getVolume()
{
    return M_PI * (radius * radius) * height;
}

double cylinderType::getSurfaceArea()
{
    return ((2 * M_PI * radius * height) + (2 * M_PI * (radius * radius))); //changed
}

double cylinderType::getHeight() {return height;}
//double cylinderType::getBaseRadius() {return base.getRadius();}
//pointType cylinderType::getCenterpoint() {return base.getCenterpoint();}

void cylinderType::setHeight(double _height) {height = _height;}
//void cylinderType::setBaseRadius(double _base_radius) {base.setRadius(_base_radius);}
//void cylinderType::setCenterpoint(pointType point) {base.setCenterpoint(point);}
/*
void cylinderType::setCenterpoint(int _x, int _y)
{
    pointType point(_x, _y);
    base.setCenterpoint(point);
}
*/

void cylinderType::inputCylinder()
{
    //base.inputCircle();
    centerpoint.inputPoint();
    cout << "\nPlease enter the cylinder's height and radius as space-separated doubles: ";
    cin >> height >> radius;
}
void cylinderType::printCylinder()
{
    //base.printCircle();
    cout << "Height: " << height << " Radius: " << radius << " Centerpoint: ";
    centerpoint.printPoint();
}
