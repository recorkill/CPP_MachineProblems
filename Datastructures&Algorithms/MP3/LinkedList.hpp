#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

class node
{
public:
    int value;
    node *next;
};


class LinkedList
{
protected:
    node *head, *tail;
public:
    LinkedList() : head(NULL), tail(NULL) {}; // When empty list is initialized, head and tail are null
    
    void addNode(); //Used to add new nodes containing random int values
    void addNode(node *new_node); //Used to add new nodes based on an existing node with existing value
    
    void printList(); //Prints each term of the linked list
    
    void sortList(); //Arranges list in ascending order
    
    void filterDuplicates(); //Removes duplicates from a linked list (used on the merged list)
    
    int getSum()
    {
        node *ptr = head;
        int return_sum = 0;
        
        while(ptr != NULL)
        {
            return_sum += ptr->value;
            ptr = ptr->next;
        }
        return return_sum;
    };
    
    
    float getAverage()
    {
        node *ptr = head;
        int return_sum = 0;
        int count = 0;
        float average;
        
        while(ptr != NULL)
        {
            return_sum += ptr->value;
            count += 1;
            ptr = ptr->next;
        }
        
        average = (float)return_sum/count;
        return average;
    };
    
    
    
    //Friend function returns a new linked list made from merging two parameter linked lists
    friend LinkedList mergeList(LinkedList const &listOne, LinkedList const &listTwo);
 
    
    
    
    
    
};










#endif /* LinkedList_hpp */
