// implementation of the DLList class

#include <stdexcept>
#include "DLList.h"

using namespace std;

// extend runtime_error from <stdexcept>
struct EmptyDLList : public std::runtime_error
{
  explicit EmptyDLList(char const *msg = nullptr) : runtime_error(msg) {}
};

// copy constructor: 
DLList::DLList(const DLList &dll)
{
  // // Initialize the list
  // header.next = &trailer;
  // trailer.prev = &header;
  
  DLListNode *dllNode = dll.first_node();
  DLListNode *newNode = new DLListNode(dllNode->obj, &header, &trailer);
  header.next = newNode;
  while (dllNode->next != dll.after_last_node())
  {
    dllNode = dllNode->next;
    newNode->next = new DLListNode(dllNode->obj, newNode, &trailer);
    newNode = newNode->next;
  }
  trailer.prev = newNode;
}


// move constructor
DLList::DLList(DLList &&dll)
{
  if(!dll.is_empty())
  {

    header.next=dll.first_node();
    trailer.prev=dll.trailer.prev;

    dll.header.next=&dll.trailer;
    dll.trailer.prev=&dll.header;

    header.next->prev=&header;
    trailer.prev->next=&trailer;
  }
  else
  {
    header.next=&trailer;
    trailer.prev=&header;
  }
}

// copy assignment operator 
DLList &DLList::operator=(const DLList &dll)
{
  if(this==&dll){return *this;} //self assignment check
  while(!is_empty()) // loop while not empty
  {
    remove_first(); //delete node
  }
  DLListNode* dllNode = dll.first_node();
  DLListNode* newNode=new DLListNode(dllNode->obj,&header,&trailer);
  header.next=newNode;
  while(dllNode->next!=dll.after_last_node())
  {
    dllNode=dllNode->next;
    newNode->next=new DLListNode(dllNode->obj,newNode,&trailer);
    newNode=newNode->next; 
  }
  trailer.prev=newNode;
  return *this;
}

// move assignment operator
DLList &DLList::operator=(DLList &&dll)
{
  if(this==&dll){return *this;} // self assignment check

  if(!dll.is_empty())
  {

    header.next=dll.first_node();
    trailer.prev=dll.trailer.prev;

    dll.header.next=&dll.trailer;
    dll.trailer.prev=&dll.header;

    header.next->prev=&header;
    trailer.prev->next=&trailer;
  }
  else
  {
    header.next=&trailer;
    trailer.prev=&header;
  }
  return *this;
}

// destructor
// from lecture notes
DLList::~DLList()
{
  DLListNode *prev_node, *node = header.next;
  while (node != &trailer)
  {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}


// insert a new object as the first one
// from lecture notes
void DLList::insert_first(int obj)
{
  DLListNode *newNode = new DLListNode(obj, &header, header.next);
  header.next->prev = newNode;
  header.next = newNode;
}

// insert a new object as the last one
// from lecture notes
void DLList::insert_last(int obj)
{
  DLListNode *newNode = new DLListNode(obj, trailer.prev, &trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}

// remove the first node from the list
// from lecture notes
int DLList::remove_first()
{
  if (is_empty())
    throw("Empty Doubly Linked List");

  DLListNode *node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  int obj = node->obj;
  delete node;
  return obj;
}

// remove the last node from the list
// from lecture notes
int DLList::remove_last()
{
  if (is_empty())
    throw("Empy Douly Linked List");

  DLListNode *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  int obj = node->obj;
  delete node;
  return obj;
}

// return the first object (do not remove)
// from lecture notes
int DLList::first() const
{
  if (is_empty())
    throw("Empty Doubly Linked List");

  return header.next->obj;
}

// return the last object (do not remove)
// from lecture notes
int DLList::last() const
{
  if (is_empty())
    throw("Empty Doubly Linked List");
  return trailer.prev->obj;
}

// insert a new node after the node p
void DLList::insert_after(DLListNode &p, int obj)
{
  DLListNode* newNode = new DLListNode(obj,&p, p.next);
  p.next->prev=newNode;
  p.next=newNode;
}

// insert a new node before the node p
void DLList::insert_before(DLListNode &p, int obj)
{
  DLListNode* newNode = new DLListNode(obj,p.prev, &p);
  p.prev->next=newNode;
  p.prev=newNode;
}

// remove the node after the node p
int DLList::remove_after(DLListNode &p)
{
  DLListNode* toDelete = p.next;
  p.next=toDelete->next;
  toDelete->next->prev=&p;
}

// remove the node before the node p
int DLList::remove_before(DLListNode &p)
{
  DLListNode* toDelete = p.prev;
  p.prev=toDelete->prev;
  toDelete->prev->next=&p;
}

// output operator
ostream &operator<<(ostream &out, const DLList &dll)
{
  DLListNode* node = dll.first_node(); // get the first node to iterate with
  const DLListNode* end = dll.after_last_node(); //used to end the loop
  while(node!=end) //exits when node=trialer
  {
    out <<node->obj<<" "; //display value of current node
    node=node->next; //move the the next node
  }
  return out;
}