#include "BinarySearchTree.hpp"
#include <string>
#include <iostream>

using namespace std;

void BST::insert(string word)
{
    node *addNode;
    node *ptr;
    
    int hite = 0;
    
    addNode = new node; //Create a new node to be inserted to the tree (and fill it with the proper data)
    
    addNode->data = word;
    addNode->rnode = NULL;
    addNode->lnode = NULL;
    
    if(this->root == NULL) {this->root = addNode; return;} //If inserting to empty BST
    
    ptr = this->root; //Set the pointer to the root (initially)
    
    bool keep_going = true;
    while(keep_going)
    {
        //This will lead to the traversal of the tree
        if((word < ptr->data) && (ptr->lnode != NULL)) {ptr = ptr->lnode; hite++;}
        else if((word > ptr->data) && (ptr->rnode != NULL)) {ptr = ptr->rnode; hite++;}
        
        //This will lead to inserting the node
        else if((word < ptr->data) && (ptr->lnode == NULL)) {ptr->lnode = addNode; hite++; keep_going = 0;}
        else if((word > ptr->data) && (ptr->rnode == NULL)) {ptr->rnode = addNode; hite++; keep_going = 0;}
        
        else {cout << "\n'" << word << "' is already stored in the BST. Skipping.\n"; keep_going = false;}
    }

    //If the insertion results in a greater hight than is previously stored, this is the new BST height
    if(height < hite) {height = hite;}
}



void BST::postOrder(node *Node)
{
    if(Node != NULL)
    {
        postOrder(Node->lnode);
        postOrder(Node->rnode);
        cout << Node->data << " ";
        
        s_postOrder += Node->data; //string to be user for insertion into next BST in main
        s_postOrder += " ";
    }
}

void BST::preOrder(node *Node)
{
    if(Node != NULL)
    {
        cout << Node->data << " ";
        preOrder(Node->lnode);
        preOrder(Node->rnode);
        
        s_preOrder += Node->data; //string to be user for insertion into next BST in main
        s_preOrder += " ";
        
    }
}

void BST::inOrder(node *Node)
{
    if(Node != NULL)
    {
        inOrder(Node->lnode);
        cout << Node->data << " ";
        inOrder(Node->rnode);
        
        s_inOrder += Node->data; //string to be user for insertion into next BST in main
        s_inOrder += " ";
    }
}
