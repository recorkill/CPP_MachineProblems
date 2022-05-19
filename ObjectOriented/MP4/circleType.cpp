#include "circleType.hpp"
#include "pointType.hpp"
#include <cmath>
#include <iostream>


using namespace std;


circleType::circleType()
{
    centerpoint = pointType();
    radius = 0;
}

circleType::circleType(double rad, pointType point) : radius(rad), centerpoint(point) {};

void circleType::setRadius(double rad) {radius = rad;}
void circleType::setCenterpoint(pointType point) {centerpoint = point;}
void circleType::setCenterpoint(int _x, int _y)
{
    pointType point(_x, _y);
    circleType::setCenterpoint(point);
}

double circleType::getRadius() {return radius;}
pointType circleType::getCenterpoint() {return centerpoint;}

double circleType::getArea() {return M_PI * (radius * radius);}
double circleType::getCircumference() {return 2 * M_PI * radius;}

void circleType::inputCircle()
{
    centerpoint.inputPoint();
    cout << "\nPlease enter a radius: ";
    cin >> radius;
}
void circleType::printCircle()
{
    cout << "\nRadius: " << radius << " Centerpoint: ";
    centerpoint.printPoint();
}
