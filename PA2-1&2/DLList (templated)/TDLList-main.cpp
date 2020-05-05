// testing the templated class DLList

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

#include "TemplatedDLList.h"

using namespace std;

int main ()
{
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DLList<string> dll;
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    stringstream ss;
    ss << i;
    dll.insert_last(ss.str());
  }
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    stringstream ss;
    ss << i;
    dll.insert_first(ss.str());
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Copy to a new list" << endl;
  DLList<string> dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  cout << "Assign to another new list" << endl;
  DLList<string> dll3;
  dll3 = dll;
  cout << "list3: " << dll3 << endl << endl;
  
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dll.remove_last();
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dll.remove_first();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;

  // more testing...
  string s = "Howdy";
  stringstream s1;
  s1 << s;

  char c = 'B';
  stringstream s2;
  s2 << c;

  int i = 17;
  stringstream s3;
  s3 << i;

  //insert before, remove after, remove before
  cout << "Inserting string: Howdy after second node in list2..." << endl << endl;
  dll2.insert_after(*dll2.first_node()->next, s1.str());
  cout << "list2:" << dll2 << endl << endl;


  cout << "Inserting char BB before second to last node in list3..." << endl << endl;
  dll3.insert_before(*dll3.after_last_node()->prev->prev, s2.str());
  cout << "list3:" << dll3 << endl << endl;


  cout << "Inserting int 17 after B in list3..." << endl << endl;
  dll3.insert_before(*dll3.after_last_node()->prev->prev, s3.str());
  cout << "list3:" << dll3 << endl << endl;

  cout << "Removing 2nd node in list2..." << endl << endl;
  dll2.remove_after(*dll2.first_node());
  cout<< "list2: " << dll2 << endl << endl;

  cout << "Removing 2nd to last node in list3..." << endl << endl;
  dll3.remove_before(*dll3.after_last_node()->prev); 
  cout<< "list3: " << dll3 << endl << endl;

 
  cout<<"Swapping 2 lists..."<<endl;
  DLList<string> temp = move(dll2);
  cout<<"Swap completed:"<<endl;
  dll2=move(dll3);
  dll3=move(temp);
  cout<<"list2: "<<dll2<<endl;
  cout<<"list3: "<<dll3<<endl;
  
  return 0;
}