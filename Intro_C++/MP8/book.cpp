#include "book.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


Book::Book()
{
    title = "Unkown title"; //These default values will help us notice any issues
    author = "No name";
    ISBN = 0;
}

//This function will take three lines from an input file and assign them to the proper variables.
void Book::getData(string path)
{
    ifstream infile;
    infile.open(path);
    string string_ISBN;
    getline(infile, author);
    getline(infile, title);
    getline(infile, string_ISBN);
    ISBN = stol(string_ISBN); //We get the ISBN as a string, but convert it to a long to assign to "ISBN"
}


const long int Book::getISBN() //This function simply returns a book's ISBN.
{
    return ISBN;
}


const void Book::Print() //This function prints out a book's information.
{
    cout << setw(15) << left << author << setw(30) <<  title << " " << ISBN << endl;
}

