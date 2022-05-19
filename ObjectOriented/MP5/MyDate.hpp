#ifndef MyDate_hpp
#define MyDate_hpp

#include <stdio.h>

class MyDate
{
protected:
    int year;
    int month;
    int day;
public:
    //Big four
    MyDate();
    MyDate(const MyDate& date);
    MyDate& operator = (const MyDate& date);
    virtual ~MyDate();
    
    MyDate(int _year, int _month, int _day);
    
    void PrintData();
    void InputData();
};


#endif /* MyDate_hpp */
