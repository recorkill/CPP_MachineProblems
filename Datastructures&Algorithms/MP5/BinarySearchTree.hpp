#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class node
{
public:
    string data;
    node *lnode;
    node *rnode;
    node() : data("") {lnode = NULL; rnode = NULL;};
};

class BST
{
    node *root;
    int height;
    int leaves;
public:
    string s_inOrder, s_postOrder, s_preOrder;
    BST() : height(0), leaves(0) {root = NULL;};
    
    
    void insert(string word);
    
    //The traversing functions will create (and return) a new BST by inserting each entry into the new tree
    void preOrder(node *Node);
    void postOrder(node *Node);
    void inOrder(node *Node);
    
    int getHeight()
    {
        return height;
    }
    
    void getLeaves() {cout << "Total Leaves: " << getLeaves(root) << endl;};
    int getLeaves(node *Node)
    {
        if (Node==NULL) {return 0;}
        else { return( 1 + getLeaves(Node->lnode) + getLeaves(Node->rnode)); }
    };
    
    void do_preOrder()
    {
        preOrder(root);
        
    };
    
    void do_postOrder() {postOrder(root);};
    void do_inOrder() {inOrder(root);};
};








#endif /* BinarySearchTree_hpp */
