#include "pointType.hpp"
#include <iostream>

using namespace std;


pointType::pointType() : x(0), y(0) {};
pointType::pointType(int _x, int _y) : x(_x), y(_y) {};

void pointType::setPoint(int _x, int _y) {x = _x; y = _y;}

int pointType::getx() {return x;}
int pointType::gety() {return y;}

void pointType::printPoint() {cout << x << "," << y;}
void pointType::inputPoint()
{
    char middle;
    cout << "\nPlease input a coordinate pair in the form x,y: ";
    cin >> x >> middle >>  y;
}


