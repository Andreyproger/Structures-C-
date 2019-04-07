#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <complex>

namespace andre{
template <typename T>
class ForwardList
{
  struct Node
  {
    T data;
    Node * next; 
  };
  
  Node first;
  Node last;
  
public:
  Forward() : first(NULL), last(NULL) // initialization before 
  {}
  
  ~Forward()
  {
    while(first)
    {
      first = first->next;
      delete first;
    }
  }
  
  void push_front(T value)
  {
    if (!first)
    {
      first = new Node();
      
      first->data = value;
      first->next = NULL;
      
      last = first;
    } else {
      Node * n = new Node();
      
      n->data = value;
      n->next = first;
      
      first = n;
    }
  }
  
  void push_back(T value)
  {
    if (!last)
    {
      last = new Node();
      
      last->data = value;
      last->next = NULL;
      
      first = last;
    }
  }
};
}
