#ifndef LLIST_H
#define LLIST_H
#include <iostream>

using namespace std;

// A singly linked list template class

template <typename T>
struct node
{
	T data;
	node<T>* next;
};

template <typename T>
class llist
{
public:
    llist<T>();

    /// Adding things to the list
    void push_back(const T&);
    void insert(unsigned int, const T&);

    /// Getting data from the list
    node<T>* last();
    unsigned int size();
    T* data();

    void print();


    node<T>* operator[](unsigned int idx)
    {
        return getn(idx);
    }

    virtual ~llist();
private:
	node<T>* m_start;

	node<T>* newNode(const T&);

    node<T>* getn(unsigned int idx)
    {
        cout << "operator[] called" << endl;
        node<T>* current = m_start;
        for(unsigned int i = 0; i < idx; i++)
        {
            current = current->next;
        }

        //TODO: Add bounds checking?
        if(current == 0)
        {
            cout << "Tried to access nullptr" << endl;
            return m_start;
        }
        cout << "operator[] returned successfully" << endl;
        return current;
    }
};

#endif // LLIST_H
