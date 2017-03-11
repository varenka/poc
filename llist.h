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
    node<T>* last();

    node<T>& operator[](unsigned int idx)
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
