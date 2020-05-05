#ifndef MINQUEUE_H
#define MINQUEUE_H

#include <stdexcept>
#include <iostream>
#include "TemplatedDLList.h"

struct EmptyMinQueue : public std::runtime_error
{
  explicit EmptyMinQueue(char const *msg = nullptr) : runtime_error(msg) {}
};

template <typename T>
class MinQueue
{
private:
  DLList<T> queue;
  int sz;

public:
  MinQueue() : sz(0) {}
  int get_size() { return sz; }
  bool is_empty() { return sz == 0; }
  const DLList<T> &print() const { return queue; }
  void enqueue(T obj)
  {
    queue.insert_last(obj);
    sz = sz + 1;
  }

  T dequeue()
  {
    if (is_empty())
      throw EmptyMinQueue("Error in dequeue(): Empty Queue");
    T value = queue.remove_first();
    sz = sz - 1;
    return value;
  }

  T min()
  {
    if (is_empty())
    {
      throw EmptyMinQueue("Error in min(): Empty Queue");
    }

    T minimum = queue.first();
    for (DLListNode<T> *node = queue.first_node(); node != queue.after_last_node(); node = node->next)
    {
      if (node->obj < minimum)
        minimum = node->obj;
    }
    return minimum;
  }
};

#endif