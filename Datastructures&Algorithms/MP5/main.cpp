#include <iostream>
#include "BinarySearchTree.hpp"
#include <string>
#include <sstream>

using namespace std;

/*
 Objectives:
 1. Input a line of text
 
 2. Tokenize the line into seperate words
 
 3. Insert words into a binary search tree, T1
 
 4. Do a postorder traversal of tree T1 and print it, insert them into tree T2
 
 5. Do a preorder traversal of tree T2 and print it, insert into tree T3
 
 6. Do an inorder traversal of tree T3 and print it.
 
 7. Print heights and number of leafs in each of T1, T2, T3
 */

void MP5()
{
    BST T1, T2, T3;
    
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence); //Get the line of text from the user
    
    istringstream iss1(sentence);
    while(iss1 >> sentence) {T1.insert(sentence);}
    
    cout << "\n\nPerforming a postorder traversal and creating a second tree...\n";
    
    T1.do_postOrder();
    string T1_postorder = T1.s_postOrder;
    
    //A string of words from the postorder traversal are inserted into the next tree
    istringstream iss2(T1_postorder);
    while(iss2 >> sentence) {T2.insert(sentence);}
    
    cout << "\n\nPerforming a preorder traversal and creating a third tree...\n";
    
    T2.do_preOrder();
    string T2_preorder = T2.s_preOrder;
    
    //A string of words from the preorder traversal are inserted into the next tree
    istringstream iss3(T2_preorder);
    while(iss3 >> sentence) {T3.insert(sentence);}
    
    cout << "\n\nPerforming an inorder traversal...\n";
    T3.do_inOrder();
    
    cout << "\n\n---Tree Sizes---\n\n";
    //Get and print the heights and leaf number for each tree
    
    cout << "Tree 1 height: " << T1.getHeight() << endl;
    T1.getLeaves();
    
    cout << "\nTree 2 height: " << T2.getHeight() << endl;
    T2.getLeaves();
    
    cout << "\nTree 3 height: " << T3.getHeight() << endl;
    T3.getLeaves();
    
    cout << endl << endl;
    
}

int main()
{
    cout << "Ryan Corkill\nCPS 272\nApril 25, 2022\nMachine Problem 5, Binary Search Trees\n\n";
    
    MP5();
}
