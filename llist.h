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

    unsigned int size();
    void push_back(const T&);
    node<T>* last();

    void print();

    node<T>& operator[](unsigned int idx)
    {
        cout << "operator[] called" << endl;
        node<T>* current;
        for(unsigned int i = 0; i < idx; i++)
        {
            current = current->next;
        }

        //TODO: Add bounds checking?
        if(current == 0)
        {
            cout << "Tried to access nullptr" << endl;
            return;
        }
        cout << "operator[] returned successfully" << endl;
        return current;
    }
    node<T>& operator[](unsigned int idx) const
    {
        return this[idx];
    }

    virtual ~llist();
private:
	node<T>* m_start;

	node<T>* newNode(const T&);
};

#endif // LLIST_H
