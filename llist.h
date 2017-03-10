#ifndef LLIST_H
#define LLIST_H

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

    node<T>& operator[](size_t);
    const node<T>& operator[](size_t);

    virtual ~llist();
private:
	node<T>* m_start;

	node<T>* newNode(const T&);
};

#endif // LLIST_H
