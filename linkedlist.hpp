#ifndef LINKEDLIST_H
#define LINKEDLIST_H



#include <stdint.h>


//----------------------------------------------------------------------------------------------------------------
/// This class is a definition of a linked list.
/// it is a generic singly linked that can be used for anything.
//----------------------------------------------------------------------------------------------------------------
template<typename T>
class LinkedList
{
public:







private:
    struct node
    {
        T data;
        node* next;
    };

    // points to the first element of the list
    node* list;

    // points to current element for the iterator
    node* current;

    int32_t size;


};

#endif // LINKEDLIST_H
