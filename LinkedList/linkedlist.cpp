#include "linkedlist.hpp"
#include <stdint.h>

//----------------------------------------------------------------------------------------------------------------
// this is the definition of the LinkedListClass
//----------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------
// constructor
//----------------------------------------------------------------------------------------------------------------
template<typename T>
LinkedList<T>::LinkedList(): list(NULL), current(NULL), size(0)
{
}

//----------------------------------------------------------------------------------------------------------------
// destructor
//----------------------------------------------------------------------------------------------------------------
template<typename  T>
LinkedList<T>::~LinkedList()
{
    this->empty();
}

//----------------------------------------------------------------------------------------------------------------
/// put
//----------------------------------------------------------------------------------------------------------------
template<typename T>
void LinkedList<T>::put(T item)
{
    node* curr = list;
    node* prev = NULL;

    while(true)
    {
        // if last element in the list
        if(curr == NULL)
        {
            curr = new node;
            curr->data = item;
            curr->next = NULL;

            // if list was empty, initialize iterator
            if(size == 0)
            {
                current = list;
            }
            size++;
            break;
        }
        else if(item > curr->data) // finding right place
        {
            curr = curr->next;
            prev = curr;
        }
        else // puts the item in between prev and curr
        {
            node* temp = new node;
            temp->data = item;
            temp->next = curr;
            prev->next = temp;
            size++;
            break;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------
/// empty
//----------------------------------------------------------------------------------------------------------------
template<typename T>
void LinkedList<T>::empty()
{
    node* temp;
    while(list != NULL)
    {
        temp = list;
        list = list->next;
        delete temp;
    }
    size = 0;
}

//----------------------------------------------------------------------------------------------------------------
/// isEmpty
//----------------------------------------------------------------------------------------------------------------
template<typename T>
bool LinkedList<T>::isEmpty()
{
    return (size == 0);
}

//----------------------------------------------------------------------------------------------------------------
/// reset
//----------------------------------------------------------------------------------------------------------------
template<typename T>
void LinkedList<T>::reset()
{
    current = list;
}

//----------------------------------------------------------------------------------------------------------------
/// next
//----------------------------------------------------------------------------------------------------------------
template<typename T>
bool LinkedList<T>::next(T& item)
{
    item = current->data;
    if(current->next != NULL)
    {
        current = current->next;
        return true;
    }
    return false;
}

//----------------------------------------------------------------------------------------------------------------
/// del
//----------------------------------------------------------------------------------------------------------------
template<typename T>
void LinkedList<T>::del(T& item)
{
    // return value
    bool rc = false;

    node* prev = NULL;
    for(node* curr = list; curr != NULL; curr = curr->next)
    {
        if(item == curr->data)
        {
            if(curr == list)
            {
                list = list->next;
            }
            else
            {
                prev->next = curr->next;
            }
            delete curr;
            rc = true;
            break;
        }
        prev = curr;
    }
   return rc;s
}
