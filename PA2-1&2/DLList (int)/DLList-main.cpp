// test of the DLList class

#include <iostream>
#include <cstdlib>
#include "DLList.h"

using namespace std;

int main ()
{
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DLList dll;
  cout << "list: " << dll << endl << endl;
  
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10; i <= 100; i+=10) {
    dll.insert_last(i);
  }
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10; i <= 100; i+=10) {
    dll.insert_first(i);
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Copy to a new list" << endl;
  DLList dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  cout << "Assign to another new list" << endl;
  DLList dll3;
  dll3 = dll;
  cout << "list3: " << dll3 << endl << endl;
  
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0; i < 10; i++) {
    dll.remove_last();
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0; i < 10; i++) {
    dll.remove_first();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;
  cout << endl;

  // more testing...
  dll2.insert_after(*dll2.first_node()->next,17);
  cout<<"Inserting 17 after 2nd node in list2... "<<endl<<"list2: "<<dll2<<endl<<endl;

  dll3.insert_before(*(dll3.after_last_node()->prev->prev),17); 
  cout<<"Inserting 17 before 2nd to last node in list3..." <<endl<<"list3: "<<dll3<<endl<<endl;

  dll2.remove_after(*dll2.first_node());
  cout<<"Removing 2nd node in list2..."<<endl<<"list2: "<<dll2<<endl<<endl;

  dll3.remove_before(*dll3.after_last_node()->prev); 
  cout<<"Removing 2nd to last node in list3..."<<endl<<"list3: "<<dll3<<endl<<endl;

  
  cout<<"Swapping 2 lists..."<<endl;
  DLList temp(move(dll2));
  cout<<"Swap completed:"<<endl;
  dll2=move(dll3);
  dll3=move(temp);
  cout<<"list2: "<<dll2<<endl;
  cout<<"list3: "<<dll3<<endl;
  
  return 0;
}