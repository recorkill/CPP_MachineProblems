#include "MyDate.hpp"
#include <iostream>

using namespace std;

MyDate::MyDate() : year(0), month(0), day(0) {}; //Empty constructor
MyDate::MyDate(const MyDate& date) : year(date.year), month(date.month), day(date.day) {}; //Copy construct
MyDate::MyDate(int _year, int _month, int _day) : year(_year), month(_month), day(_day) {};

MyDate::~MyDate() {}

void MyDate::InputData() {cin >> month >> day >> year;} ;
void MyDate::PrintData() {cout << month << "/" << day << "/" << year;} ;

MyDate& MyDate::operator = (const MyDate& date) {year = date.year; month = date.month; day = date.day; return *this;}

