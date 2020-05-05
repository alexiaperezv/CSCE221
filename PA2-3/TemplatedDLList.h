// header file for the templated DLList

#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H
// implementation of the DLList class

#include <stdexcept>
#include <iterator>
#include <iostream>
#include <string>

using namespace std;

struct EmptyDLList : public std::runtime_error
{
    explicit EmptyDLList(char const *msg = nullptr) : runtime_error(msg) {}
};

// Node
template <typename T>
struct DLListNode
{
    T obj;
    DLListNode *prev, *next;
    // constructor
    DLListNode(T e = T(), DLListNode *p = nullptr, DLListNode *n = nullptr)
        : obj(e), prev(p), next(n) {}
};

// DLL Templated Class
template <typename T>
class DLList
{
private:
    DLListNode<T> header, trailer;

public:
    DLList() // default constructor
    {
        header.next = &trailer;
        trailer.prev = &header;
    }

    DLList(const DLList<T> &dll)
    {
        DLListNode<T> *dllNode = dll.first_node();
        DLListNode<T> *newNode = new DLListNode<T>(dllNode->obj, &header, &trailer);
        header.next = newNode;
        while (dllNode->next != dll.after_last_node())
        {
            dllNode = dllNode->next;
            newNode->next = new DLListNode<T>(dllNode->obj, newNode, &trailer);
            newNode = newNode->next;
        }
        trailer.prev = newNode;
    } // copy constructor

    DLList(DLList &&dll) // move constructor
    {
        if (!dll.is_empty())
        {

            header.next = dll.first_node();
            trailer.prev = dll.trailer.prev;

            dll.header.next = &dll.trailer;
            dll.trailer.prev = &dll.header;

            header.next->prev = &header;
            trailer.prev->next = &trailer;
        }
        else
        {
            header.next = &trailer;
            trailer.prev = &header;
        }
    }

    ~DLList() // destructor
    {
        while (first_node() != after_last_node())
        {
            remove_first();
        }
    }

    DLList &operator=(const DLList &dll) // copy assignment operator
    {
        if (this == &dll)
        {
            return *this;
        }                   //self assignment check
        while (!is_empty()) // loop while not empty
        {
            remove_first(); //delete node
        }
        DLListNode<T> *dllNode = dll.first_node();
        DLListNode<T> *newNode = new DLListNode<T>(dllNode->obj, &header, &trailer);
        header.next = newNode;
        while (dllNode->next != dll.after_last_node())
        {
            dllNode = dllNode->next;
            newNode->next = new DLListNode<T>(dllNode->obj, newNode, &trailer);
            newNode = newNode->next;
        }
        trailer.prev = newNode;
        return *this;
    }

    DLList &operator=(DLList &&dll) // move assignment operator
    {
        if (this == &dll)
        {
            return *this;
        } // self assignment check

        if (!dll.is_empty())
        {

            header.next = dll.first_node();
            trailer.prev = dll.trailer.prev;

            dll.header.next = &dll.trailer;
            dll.trailer.prev = &dll.header;

            header.next->prev = &header;
            trailer.prev->next = &trailer;
        }
        else
        {
            header.next = &trailer;
            trailer.prev = &header;
        }
        return *this;
    }
    // return the pointer to the first node
    DLListNode<T> *first_node() const { return header.next; }
    // return the pointer to the trailer
    const DLListNode<T> *after_last_node() const { return &trailer; }
    // return if the list is empty
    bool is_empty() const { return header.next == &trailer; }
    T first() const
    {
        return header.next->obj;
    } // return the first object

    T last() const // return the last object
    {
        return trailer.prev->obj;
    }

    void insert_first(T obj) // insert to the first node
    {
        DLListNode<T> *newNode = new DLListNode<T>(obj, &header, header.next);
        header.next->prev = newNode;
        header.next = newNode;
    }


    void insert_last(T obj) // insert to the last node
    {
        DLListNode<T> *newNode = new DLListNode<T>(obj, trailer.prev, &trailer);
        trailer.prev->next = newNode;
        trailer.prev = newNode;
    }

    T remove_first() // remove the first node 
    {
        DLListNode<T> *toDelete = header.next;
        header.next = toDelete->next;
        header.next->prev = &header;
        T retVal = toDelete->obj;
        delete toDelete;
        return retVal;
    }
    
    T remove_last() // remove the last node
    {
        if (is_empty())
        {
            throw EmptyDLList("Empty List");
        }
        DLListNode<T> *toDelete = trailer.prev;
        toDelete->prev->next = &trailer;
        trailer.prev = toDelete->prev;
        T ret = toDelete->obj;
        delete toDelete;
        return ret;
    }

    void insert_after(DLListNode<T> &p, T obj)
    {
        DLListNode<T> *newNode = new DLListNode<T>(obj, &p, p.next);
        p.next->prev = newNode;
        p.next = newNode;
    }
    void insert_before(DLListNode<T> &p, T obj)
    {
        DLListNode<T> *newNode = new DLListNode<T>(obj, p.prev, &p);
        p.prev->next = newNode;
        p.prev = newNode;
    }
    T remove_after(DLListNode<T> &p) // ----> DOESN'T WORK
    {
        DLListNode<T> *toDelete = p.next;
        p.next = toDelete->next;
        toDelete->next->prev = &p;
        T ret = toDelete->obj;
        delete toDelete;
        return ret;

    }
    T remove_before(DLListNode<T> &p) // ----> DOESN'T WORK
    {
        DLListNode<T> *toDelete = p.prev;
        p.prev = toDelete->prev;
        toDelete->prev->next = &p;
        T ret = toDelete->obj;
        delete toDelete;
        return ret;
    }
};

// output operator
template <typename T>
ostream &operator<<(ostream &out, const DLList<T> &dll)
{
    DLListNode<T> *node = dll.first_node();           // get the first node to iterate with
    const DLListNode<T> *end = dll.after_last_node(); //used to end the loop
    while (node != end)                               //exits when node=trialer
    {
        out << node->obj << " "; //display value of current node
        node = node->next;       //move the the next node
    }
    return out;
}

#endif