#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <algorithm>

#include "fraction.hpp"

/*
 OBJECTIVES:
 
 1) Overload the >> operator for reading in from a data file. Make sure the Fraction is reduced after it is read in
 2) Read the FractsToVector.txt data file into a Vector of Fractions and return that vector sorted to the main function
 3) Read the FractsToList.txt data file into a List of Fractions and return that list sorted to the main function
 4) Now pass the sorted Vector and the sorted List into a Merge function. The Merge function will then combine the two into a new Vector of Fractions. Make sure the new Vector does NOT contain any duplicates. Return that new vector of Fractions sorted back to the main function.
 5) Print out the first Vector, the List and the merged Vector to the screen
 */



using namespace std;

bool ascending_order (Fraction i,Fraction j) { return (i<j); }


void remove_duplicates(vector<Fraction> &fract_vector)
{
    auto end = fract_vector.end();
    for (auto index = fract_vector.begin(); index != end; ++index) {
        end = remove(index + 1, end, *index);
    }
 
    fract_vector.erase(end, fract_vector.end());
}



list<Fraction> read_to_list(string path)
{
    list<Fraction> fract_list;
    ifstream infile;
    infile.open(path);
    Fraction fract;
    while(infile >> fract && infile.good()) {fract_list.push_back(fract);}
    
    fract_list.sort(ascending_order);  //Sort list into ascending order
    return fract_list;
}


vector<Fraction> read_to_vector(string path)
{
    vector<Fraction> fract_vector;
    ifstream infile;
    infile.open(path);
    Fraction fract;
    while(infile >> fract && infile.good()) {fract_vector.push_back(fract);}
    
    sort(fract_vector.begin(), fract_vector.end(), ascending_order); //Sort vector into ascending order
    return fract_vector;
}

template<typename fract_or_list>
void print(fract_or_list printable)
{
    for (auto item : printable)
        cout << item << "\n";
}



vector<Fraction> merge(vector<Fraction> item1, list<Fraction> item2)
{
    vector<Fraction> merged_vector;
    
    for (auto item : item1)
        merged_vector.push_back(item);
    for (auto item : item2)
        merged_vector.push_back(item);
    
    sort(merged_vector.begin(), merged_vector.end(), ascending_order); //Sort vector into ascending order
    remove_duplicates(merged_vector); //Remove duplicate values

    return merged_vector;
}






int main()
{
    list<Fraction> fract_list = read_to_list("FractsToList.txt"); //Fractions to list
    vector<Fraction> fract_vector = read_to_vector("FractsToVector.txt"); //Fractions to vector
    vector<Fraction> merged_vector = merge(fract_vector, fract_list); //Merged both to a vector
    
    cout << "Ryan Corkill\nCPS 271\nMarch 17, 2022\nMachine Problem 8" << endl << endl;
    
    cout << "***** Sorted vector of Fractions *****" << endl << endl;
    print(fract_vector);
    
    cout << "\n\n***** Sorted list of Fractions *****" << endl << endl;
    print(fract_list);
    
    cout << "\n\n***** Merged sorted vector *****" << endl << endl;
    print(merged_vector);
    
    cout << endl << endl;


}
