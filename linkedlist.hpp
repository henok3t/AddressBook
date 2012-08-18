#ifndef LINKEDLIST_H
#define LINKEDLIST_H



#include <stdint.h>


//----------------------------------------------------------------------------------------------------------------
/// This class is a definition of a linked list.
/// it is a generic singly linked that can be used for anything.
/// NOTE: the item being put into the Linkedlist must implement the comparing operators, < > == ...
//----------------------------------------------------------------------------------------------------------------
template<typename T>
class LinkedList
{
public:
    //----------------------------------------------------------------------------------------------------------------
    /// @constructor
    /// initializes list to empty
    //----------------------------------------------------------------------------------------------------------------
    LinkedList();

    //----------------------------------------------------------------------------------------------------------------
    /// destructor
    /// deletes list and frees all memory
    //----------------------------------------------------------------------------------------------------------------
    ~LinkedList();

    //----------------------------------------------------------------------------------------------------------------
    /// @brief
    /// put an item into the list (sorted)
    /// @param item
    /// the item to be put into the list
    /// @return
    /// true for success, false for failure
    //----------------------------------------------------------------------------------------------------------------
    bool put(T item);

    //----------------------------------------------------------------------------------------------------------------
    /// @brief
    /// checks if list is empty
    /// @return
    /// true if empty, false otherwise
    //----------------------------------------------------------------------------------------------------------------
    bool isEmpty();

    //----------------------------------------------------------------------------------------------------------------
    /// @brief
    /// resets list for iteration
    /// @return
    /// true for success, false for failure
    //----------------------------------------------------------------------------------------------------------------
    bool reset();

    //----------------------------------------------------------------------------------------------------------------
    /// @brief
    /// gets the next element in the list
    /// @return
    /// returns true if there is a next item, false otherwise
    //----------------------------------------------------------------------------------------------------------------
    bool next(T& item);

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

    // number of elements in the list
    int32_t size;


};

#endif // LINKEDLIST_H
