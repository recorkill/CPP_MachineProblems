//
//  book.hpp
//  MP8
//
//  Created by Ryan on 1/27/22.
//

#ifndef book_hpp
#define book_hpp

#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

//In this header file, we declare our variables for the class "Book".
class Book
{
    string author, title;
    long int ISBN;
    
public:
    Book();
    const void Print();
    void getData(string);
    const long int getISBN();

};
#endif /* book_hpp */
