#include "llist.h"

template <typename T>
llist<T>::llist()
{

}

template <typename T>
llist<T>::~llist()
{
    // Delete entire list
    node<T>* current = m_start;
    node<T>* deleted = m_start;

    while(current != 0)
    {
        deleted = current;

        current = current->next;

        delete deleted;
    }
}

// Creates a new node with data d
template <typename T>
node<T>* llist<T>::newNode(const T& d)
{
    node<T>* n = new node<T>;
    n->data = d;
    n->next = 0;
    return n;
}

// Returns the number of elements in the list
template <typename T>
unsigned int llist<T>::size()
{
    node<T>* current = m_start;
    unsigned int i = 1;
    while(current->next != 0)
    {
        current = current->next;
        i++;
    }
    return i;
}

// Add a new node at the end of the list
template <typename T>
void llist<T>::push_back(const T& d)
{
    node<T>* n = newNode(d);


}

// Overloaded array subscript functions to access the list like a vector
template <typename T>
node<T>& llist<T>::operator[](size_t idx)
{
    node<T>* current;
    for(unsigned int i = 0; i < idx; i++)
    {
        current = current->next;
    }

    //TODO: Add bounds checking?
    /*if(current == 0)
    {
        return
    }*/
    return current;
}

