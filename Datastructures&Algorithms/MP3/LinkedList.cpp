#include "LinkedList.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;


void LinkedList::addNode()
{
    int random_val = rand() % 100; //Each new node will have a random value between 0 and 100
    
    node *new_node = new node;
    new_node->value = random_val;
    new_node->next = NULL;
    
    if(head == NULL) //In the event head is NULL (i.e., if we are adding the first node to the list)
    {
        head = new_node;
        tail = new_node;
    }
    
    else //This portion will execute when the new node is NOT the first node being added to the list
    {
        tail->next = new_node; //set the (former) tail's pointer to the new node being added
        tail = tail->next; //Set (new) tail node to the new node we are adding
    }
}

void LinkedList::addNode(node *new_node)
{
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    
    else
    {
        tail->next = new_node;
        tail = tail->next;
    }
}


void LinkedList::sortList()
{
    /*Two ptrs, PTR1 and PTR2. PTR1 will point at the nearest node to the sorted node(s) (starting at head, moving down one after every loop). PTR2 will point at the node next to PTR1 to begin each loop, and traverse the list each loop, swapping terms with PTR1 every time it finds a lower value.
    */
    
    node *PTR1 = head;
    node *PTR2;
    
    while(PTR1->next != NULL)
    {
        PTR2 = PTR1->next;
        
        while(PTR2 != NULL)
        {
            if(PTR2->value < PTR1->value)
            {
                int tmp = PTR1->value;
                PTR1->value = PTR2->value;
                PTR2->value = tmp;
            }
            PTR2 = PTR2->next;
        }
        PTR1 = PTR1->next;
    }
}



void LinkedList::filterDuplicates()
{
    LinkedList filteredList;
    
    // 1 -> 2 -> 3 -> 4 ...... can "delete" 3 by setting 2's "next" address to 4 (routes around 3)
    
    node *point = head;
    
    while(point->next != NULL)
    {
        if(point->value == point->next->value)
        {
            point->next = point->next->next;
        }
        point = point->next;
        
    }
    
}














void LinkedList::printList()
{
    /// traversing a linked list
    node *pointer = head; //create a pointer that will traverse the linked list
    
    while(pointer != NULL) //(While the end of the list is not yet reached)
    {
        
        cout << pointer->value << " ";
        
        pointer = pointer->next;
    }
    
    
}

//Designed to merge two sorted lists
LinkedList mergeList(LinkedList const &listOne, LinkedList const &listTwo)
{
    /*
    LinkedList mergedList;
    ///get count of nodes in list one and two, for int i = 0, i < count, i++, add node
    
    node *listOnePTR = new node;
    node *listTwoPTR = new node;
    
    listOnePTR = listOne.head;
    listTwoPTR = listTwo.head;
    
    while(!((listOnePTR == NULL) && (listTwoPTR == NULL))) //While both lists aren't empty (head = NULL)
    {
        if((listOnePTR->value <= listTwoPTR->value) || (listTwoPTR == NULL)) //If list one <= list two
        {
            mergedList.addNode(listOnePTR);
            listOnePTR = listOnePTR->next;
        }
        if((listTwoPTR->value < listOnePTR->value) || (listOnePTR == NULL))
        {
            mergedList.addNode(listTwoPTR);
            listTwoPTR = listTwoPTR->next;
        }
    }
    
    return mergedList;
     */
    
    LinkedList mergedList;
    
    //node *listOnePTR = new node;
    //node *listTwoPTR = new node;
    
    node *listOnePTR = listOne.head;
    node *listTwoPTR = listTwo.head;
    
    while(listOnePTR != NULL)
    {
        mergedList.addNode(listOnePTR);
        listOnePTR = listOnePTR->next;
    }
    
    while(listTwoPTR != NULL)
    {
        mergedList.addNode(listTwoPTR);
        listTwoPTR = listTwoPTR->next;
    }
    
    mergedList.sortList();
    
    return mergedList;
    
}
