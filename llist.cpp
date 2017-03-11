#include "llist.h"

template <typename T>
llist<T>::llist()
{
    m_start = 0;
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
    if(m_start == 0)
    {
        return 0;
    }

    node<T>* current = m_start;
    unsigned int i = 1;
    while(current->next != 0)
    {
        current = current->next;
        i++;
    }
    return i;
}

// Returns the last element in the list, or 0 if the list is empty
template <typename T>
node<T>* llist<T>::last()
{
    return this[this.size() - 1];
}

// Add a new node at the end of the list
template <typename T>
void llist<T>::push_back(const T& d)
{
    node<T>* n = newNode(d);

    // If there is nothing else already in the list, make this the starting element
    if(m_start == 0)
    {
        m_start = n;
        return;
    }

    // else
    this[this.size() - 1]->next = newNode(d);
}
