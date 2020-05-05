// topological sort

#include <iostream>
#include "graph.h"

void Graph::compute_indegree()
{
  for (int k = 0; k < node_list.size(); k++)
  {
    int counter = 0;
    for (int i = 0; i < adj_list.size(); i++)
    {
      list<int> l = *adj_list[i];
      for (list<int>::iterator it = l.begin(); it != l.end(); it++)
      {
        if (node_list[k].label == *it)
        {
          counter++;
        }
      }
    }
    node_list[k].indegree = counter;
  }
}

void Graph::topological_sort()
{
  queue<Vertex *> q; // create queue to store vertices with indegree 0
  int counter = 0;
  make_empty(q);
  //cout << "Test 1.1" << endl;
  for (int i = 0; i < node_list.size(); i++)
  {
    if (node_list[i].indegree == 0)
    {
      q.push(&node_list[i]);
    }
  }
  //cout << "Test 1.2" << endl;

  while (!q.empty())
  {
    Vertex *v = q.front();
    q.pop();
    v->top_num = ++counter; // assigns next number
    list<int> l;
    //cout << "Test 1.3" << endl;
    for (int i = 0; i < node_list.size(); i++)
    {
      if (node_list[i].label == v->label)
      {
        l = *adj_list[i];
      }
    }
    //cout << "Test 1.4" << endl;
    for (list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
      // cout << "Test 1.5" << endl;
      for (int j = 0; j < node_list.size(); j++)
      {
        if (node_list[j].label == *it)
        {
          if (--node_list[j].indegree == 0)
          {
            q.push(&node_list[j]);
          }
        }
      }
    }
  }
  //cout << "Test 1.7" << endl;
  if (counter != node_list.size())
  {
    //  cout << "Test 1.8" << endl;
    throw logic_error("ERROR: A Cycle was found.");
  }
  //cout << "Test 1.9" << endl;
}

void Graph::print_top_sort()
{
  for (int i = 1; i <= node_list.size(); i++)
  {
    for (int j = 0; j < node_list.size(); j++)
    {
      if (node_list[j].top_num == i)
      {
        cout << node_list[j].label << " ";
      }
    }
  }
  cout << endl;
}

void Graph::make_empty(queue<Vertex *> q) // Helper function to make sure queue is empty!
{
  while (!q.empty()) // makes sure queue is empty
  {
    q.pop();
  }
}