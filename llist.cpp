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
    if(m_start == 0)
    {
        return m_start;
    }

    node<T>* current = m_start;

    while(current->next != 0)
    {
        current = current->next;
    }
    return current;
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
    last()->next = n;
}

// Add a new node after the node at this[idx], and before this[idx + 1] (if it exists)
template <typename T>
void llist<T>::insert(unsigned int idx, const T& d)
{
    node<T>* n = newNode(d);

    if(m_start == 0)
    {
        cout << "Tried to insert() into an empty list" << endl;
        return;
    }

    n->next = getn(idx)->next;
    getn(idx)->next = n;
}

template <typename T>
void llist<T>::print()
{
    if(m_start == 0)
    {
        return;
    }

    node<T>* current = m_start;
    cout << "Printing linked list:" << endl;
    while(current != 0)
    {
        cout << "\tdata = " << current->data << endl;
        cout << "\tnext = " << current->next << endl;

        current = current->next;
    }
}

// Creates an array of the entire list. must be delete[]ed after it is used
template <typename T>
T* llist<T>::data()
{
    if(m_start == 0)
    {
        return 0;
    }
    // allocate memory
    T* pointer = new T[size()];

    node<T>* current = m_start;
    // add data
    for(unsigned int i = 0; i < size(); i++)
    {
        pointer[i] = current->data;

        current = current->next;
    }

    return pointer;
}
