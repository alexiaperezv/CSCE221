
#include <iostream>
#include <fstream>
#include "BSTree.h"
#include <vector>

BSTree read_file(string file_name)
{
  ifstream ifs(file_name);
  BSTree new_tree; // Creates new tree (using constructor)
  if(ifs.is_open()) // If file is open
  {
    vector<int> input; //create new vector
    int num;
    int count;
    while(!ifs.eof()) // while not the end of the file
    {
      count++; // increase the counter to calculate number of inputs later
      ifs >> num; // num variable takes in value from file 
      input.push_back(num); // we add that value to our vector
    } // once we exit the loop, all inputs will have been read
    
    cout << endl << "Creating Binary Search Tree..." << endl; 
    for(int i = 0; i < input.size(); i++) // we can use the vector's size to read in every value in it
    {
      new_tree.insert(input[i]); // insert every value in our vector into our newly created tree
    } 
    cout << "Total number of nodes is: " << count << endl; // output our counter, which tells us how many nodes in the new tree
  }
  else // if file is not open
  {
    throw("Error: Cannot open file!"); // throw error
  }

  return new_tree; // if everything goes well, we return the new tree
}


int main()
{
  BSTree test = read_file("data-files/3p");
  cout << "Printing test tree... " << endl;
  test.inorder(cout);
  cout << endl << "Testing Copy Constructr. Printing copy of tree..." << endl;
  
  // Copy Constructor Test
  BSTree copy(test);
  copy.inorder(cout);

  cout << "Added new value to copy. Outputting Original v. Copy..." << endl;
  copy.insert(8000000); // Make trees different to prove the initial tree was not affected
  cout << "Orgininal:" << endl;
  test.inorder(cout);
  cout << "Copy: "<< endl;
  copy.inorder(cout);

  // Copy Assignmet Operator Test
  BSTree copy2;
  copy2 = test; // Tests the copy assignment operator
  cout << "Testing Copy Assignment Operator. Printing copy 2..." << endl;
  copy2.inorder(cout);

  // Move constructor Test
  cout << "Testing Move Constructor. Creating new tree Copy 3 and moving Copy 2 to it..." << endl;
  BSTree copy3 = move(copy2);
  cout << "Copy 3: ";
  copy3.inorder(cout);
  cout << "Copy 2: " << endl;
  copy2.inorder(cout);
  cout << endl;
  cout << "Trees left: test, copy, copy3." << endl;
  // bc after this, copy 2 does not exist

  // Move assignment operator
  cout << "Moving Copy 3 to Copy ...";
  copy = move(copy3);
  cout << "Printing Copy and Copy 3..." << endl;
  cout << "Copy: ";
  copy.inorder(cout);
  cout << "Copy 3: ";
  copy3.inorder(cout);
  cout << endl;
  cout << "Trees left: test, copy." << endl;
  // bc copy 2 was deleted earlier and this part deleted copy 3.
  
  cout << "Starting Application..." << endl;

  for(int i = 1; i <= 12; i++) {
    string dir= "data-files/"+std::to_string(i);
    BSTree l = read_file(dir+"l");
    cout << "average search time linear " << i << " "
	 << l.get_average_search_time() << endl;
    BSTree p = read_file(dir+"p");
    cout << "average search time perfect "<< i << " "
	 << p.get_average_search_time() << endl;
    BSTree r = read_file(dir+"r");
    cout << "average search time random "<< i << " "
	 << r.get_average_search_time() << endl;

    if(i <= 4) {
      cout << "prefect tree " << i << endl << p;
    }

    cout << endl;
  }
  return 0;
}