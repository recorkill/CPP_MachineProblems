#include <iostream>
#include "LinkedList.hpp"



using namespace std;



int main()
{
    cout << "Ryan Corkill\nCPS 272\nApril 13th, 2022\nMachine Problem 3, Linked Lists" << endl << endl;

    LinkedList LinkedList15, LinkedList20, MergedList; //Create the three LinkedList objects
    
    
    //Create a linked list of size 15
    for(int i = 0; i < 15; i++) {LinkedList15.addNode();}
    
    //Create a linked list of size 20
    for(int i = 0; i < 20; i++) {LinkedList20.addNode();}
    
    //Sort the lists
    LinkedList15.sortList();
    LinkedList20.sortList();
    
    //Print the two sorted lists
    cout << "List one:\n";
    LinkedList15.printList();
    
    cout << "\n\nList two:\n";
    LinkedList20.printList();
    
    //Merge the two sorted lists and print the merged list
    MergedList = mergeList(LinkedList15, LinkedList20);
    MergedList.filterDuplicates();
    cout << "\n\nMerged list:\n";
    MergedList.printList();
    
    int final_sum = MergedList.getSum();
    float final_average = MergedList.getAverage();
    
    cout << "\n\nFinal list sum: " << final_sum << "\nFinal list average: " << final_average;
    
    cout << endl << endl;
    
    
}
