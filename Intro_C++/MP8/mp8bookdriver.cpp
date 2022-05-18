#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "book.hpp"

int find_match(int ISBN, Book library[])
{
    int book_number = -1;   //If book_number is returned negative, we will know a match wasn't found
    for(int i = 0; i <= 9; i++)
    {
        int test_ISBN = library[i].getISBN();
        //Iteratively checking each book's ISBN number, returning the matching book's index number
        if(ISBN == test_ISBN)
        {
            book_number = i;
        }
    }
    return book_number;
}

//BINARY SEARCH TO FIND WHICH BOOK IN THE LIBRARY HAS THE ISBN NUMBER
int binary_find_match(Book library[], int ISBN)
//Take sorted values, compare the middle value to the ISBN number.
{
    int start = 0, end = 9; //lowest and highest index numbers
    while (start <= end)
    {
        int test_index = start + (end - start) / 2; //the test_index is the middle value.

        if (library[test_index].getISBN() == ISBN) //If the value matches the ISBN being searched, return the index number and end the search.
        {
          return test_index;
        }

        if (library[test_index].getISBN() < ISBN) //If this if statement is reached, we know a match wasn't found using the test_index number. We either ignore the higher half of the array (if the ISBN being searched is lower than the test_index), or we ignore the lower half and retry.
        {
            start = test_index + 1;
        }
        else
        {
            end = test_index - 1;
        }
  }
  return -1; //This value is returned only if no match is found (finding a match ends the loop).
}


int main()
{
    
    // BEGIN PART 1 (TESTING THE BOOK CLASS)
    Book book1, book2;
    cout << "MP8, Working with Classes by Ryan Corkill\nFebruary 2nd, 2022" << endl;
    cout << "\nPart 1 of 3, Testing the book class" << endl << endl;
    cout << "The information for book 1 is:" << endl;
    book1.Print();
    book2.getData("mp8book.txt");
    cout << "\nThe information for book 2 is:" << endl;
    book2.Print();
    cout << "Book 2 has the ISBN: " << book2.getISBN() << endl << endl;
    
    
    //BEGIN PART 2 (CREATING A LIBRARY)
    Book library[10];
    cout << "Part 2 of 3, Creating a Library" << endl << endl;
    cout << "Author" << "\t\t\t\t" << "Book Title" << "\t\t\t"<< "ISBN" << endl;
    for(int i = 0; i <= 9; i++)
    {
        ofstream loop_book;
        ifstream infile;
        infile.open("mp8bookarray.txt");
        loop_book.open("loopbook.txt");
        
        string line;
        int line_number = 0;
        
        /*
         The getData function reads the first two lines of the file passed to it. Because of this, if we were to pass the same text file contianing all of the lines each time the loop is run, the getData function would simply get the data for the first three lines over and over, returning the same book. The following while loop allows us to fill a placeholder file (loopbook.txt) with the three lines associated with each book in the library.
         */
        while(getline(infile, line))
        //WE ARE SETTING THE THREE LINES IN THE LOOPBOOK FILE TO MATCH THE BOOK NUMBER WE ARE LOOKING AT
        {
            if((line_number >= (i*3)) && (line_number < ((i*3)+3)))
            {
                loop_book << line << endl;
            }
            line_number += 1;
        }
        
        library[i].getData("loopbook.txt");
        library[i].Print();
    }
        
    // BEGIN PART 3 (TESTING ISBN NUMBERS)
    cout << endl << endl;
    cout << "Part 3 of 3, Searching the Library with ISBN Numbers\n" << endl;
    ifstream ISBNfile;
    ISBNfile.open("mp8bookISBN.txt");
    string ISBN;
    //For each line (each ISBN number), convert it to an integer and perform a binary search
    while(getline(ISBNfile, ISBN) && ISBNfile.good())
    {
        int int_ISBN = stoi(ISBN);
        int match = binary_find_match(library, int_ISBN);
        {
            if(match < 0) //A value of -1 is returned if no book is found.
            {
                cout << "No book with the ISBN number " << ISBN << " was found." << endl;
                cout << "**********************************" << endl;
            }
            else
            {
                cout << "A book with the ISBN number " << ISBN << " was found! Its information is:" << endl;
                library[match].Print();
                cout << "**********************************" << endl;
            }
        }
    }
}
