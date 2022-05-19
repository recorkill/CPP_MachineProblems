#include <iostream>
#include <cmath>

#include "pointType.hpp"
#include "circleType.hpp"
#include "cylinderType.hpp"

using namespace std;

int main()
{
    cout << "Ryan Corkill\nCPS 271\nMarch 7, 2022\nMachine Problem 4" << endl;
    
    // SHOWCASING POINT CLASS
    
    pointType point_1; // Default constructor builds point (0, 0)
    pointType point_2(1,2); // We can also directly build a point at (1,2)
    
    cout << "\nThe first point (no parameters) is: ";
    point_1.printPoint();
    cout << "\nThe second point (initialized to (1,2)) is: ";
    point_2.printPoint();
    
    point_1.setPoint(5, 7); //We can also set the value of a point
    
    cout << "\n\nThe new x-coordinate for the first point is " << point_1.getx() << "\nThe new y-coordinate for the first point is " << point_1.gety() << endl;
    
    
    
    //SHOWCASING CIRCLE CLASS
    
    circleType circle_1; // No parameters generates a circle with radius 0 and centerpoint at the origin
    circleType circle_2(3.5, point_2); // Alternatively, we an create a circle from a point and a radius
    
    cout << "\nCircle 1 has a radius of " << circle_1.getRadius() << " and a centerpoint of ";
    circle_1.getCenterpoint().printPoint();
    cout << "\nCircle 2 has a radius of " << circle_2.getRadius() << " and a centerpoint of ";
    circle_2.getCenterpoint().printPoint();
    
    circle_1.setCenterpoint(point_1); //We can also set the centerpoint of a circle (to our point 1)
    circle_1.setRadius(5.5); // and set our radius as well
    
    cout << "\n\nThe radius of circle 1 is now " << circle_1.getRadius() << " and the center is now at point ";
    circle_1.getCenterpoint().printPoint();
    
    //We can also calculate the circumferene and area of our circle object
    cout << "\nCircle 1 has a circumference of " << circle_1.getCircumference() << " and an area of " << circle_1.getArea() << "\n\n";
    

    //SHOWCASING CYLINDER CLASS
    
    cylinderType cylinder_1; // No parameters generates a cylinder with a base radius and height of 0
    cylinderType cylinder_2(5.5, point_2, 10.5); // However, we can also create our cylinder from height, radius, and pointType centerpoint
    
    cout << "Cylinder 1 has a height of " << cylinder_1.getHeight() << ", a base radius of " << cylinder_1.getRadius() << ", and a centerpoint of ";
    cylinder_1.getCenterpoint().printPoint();
    
    cout << "\nCylinder 2 has a height of " << cylinder_2.getHeight() << ", a base radius of " << cylinder_2.getRadius() << ", and a centerpoint of ";
    cylinder_2.getCenterpoint().printPoint();
    
    //Much like with the objects in circle and point classes, we can also set the values for a cylinder
    cylinder_1.setRadius(4.3);
    cylinder_1.setCenterpoint(point_1);
    cylinder_1.setHeight(14.5);
    
    cout << "\n\nCylinder 1 now has a height of " << cylinder_1.getHeight() << ", a base radius of " << cylinder_1.getRadius() << ", and a centerpoint of ";
    cylinder_1.getCenterpoint().printPoint();
    
    //We can also calculate the volume and surface area of our cylinder object
    
    cout << "\n\nThe volume of cylinder 1 is " << cylinder_1.getVolume() << " and the surface area is " << cylinder_1.getSurfaceArea() << endl << endl;
    
    
    
    //INPUT/PRINT FUNCTIONS
    cout << "\n\nInput/output functions\n" << endl;
    pointType ioPoint;
    circleType ioCircle;
    cylinderType ioCylinder;
    
    // Get/print Point Information
    cout << "Point input/output:" << endl;
    ioPoint.inputPoint();
    cout << "\n\nInformation entered for this point:";
    ioPoint.printPoint();
    
    
    // Get/print Circle Information
    cout << "\n\nCircle input/output:" << endl;
    ioCircle.inputCircle();
    cout << "\n\nInformation entered for this circle:";
    ioCircle.printCircle();
    cout << " Circumference: " << ioCircle.getCircumference() << " Area: " << ioCircle.getArea();
    
    
    // Get/print Cylinder Information
    cout << "\n\nCylinder input/output:" << endl;
    ioCylinder.inputCylinder();
    cout << "\n\nInformation entered for this cylinder:" << endl;
    ioCylinder.printCylinder();
    cout << " Volume: " << ioCylinder.getVolume() << " Surface Area: " << ioCylinder.getSurfaceArea();
    cout << endl << endl;
}
