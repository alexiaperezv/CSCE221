README File for Assignment 2 - The Class DLList (part 1)

Alexia Perez, 127008512, CSCE 221-506, alexia_perezv, alexia_perezv@tamu.edu
---------------------------------------------------------------------------------------------------------
I certify that I have listed all the sources that I used to develop the solutions and code to the submitted work.
	On my honor as an Aggie, I have neither given nor received any unauthorized help on this academic work.
Alexia Perez
February 25th, 2020
---------------------------------------------------------------------------------------------------------
Aside from a few discussions with Peer Teachers, the only other outside resource I used was: 

https://www.geeksforgeeks.org/

I used this resource to read documentation about the use of templated classes and some other small
details such as definitons for the different types of constructors and their use, etc.
 
---------------------------------------------------------------------------------------------------------
No issues found with the code submitted.
---------------------------------------------------------------------------------------------------------
The program: 

DLList.cpp is the main file I edited for this assignment. I also added some code to the main in the test file to test additional functions aside from the ones that were already implemented for me. 

For DLList.cpp: 

I wrote the copy constructor, move constructor, move assignment, copy assignment, and destructor first. The destructor, insert_first, insert_last, remove_first, remove_last, first(), last() functions all came from lecture notes.

Copy Constructor: it creates a new node that points to the first element in a list, then createf a new node with the previously created node's object as its object. Then sets the header's next ot the new node. Then it uses a while loop to copy every element from one list to the other. FInally, it sets the trailer's previous to the new node.

Move Constructor: It checks if the list is empty or not. If it is, it sets the header's next to the list's first node. Then it sets the trailer's previous to the list's trailer's previous node. Next, it sets the list's header's next to the reference value of the list's trailer. After that, it sets the list's trailer's previous to the referenced value of the list's header. Finally, it sets the header's next previous pointer to the value of header, then it sets the trailer's previous next pointer to the value of the trailer. If the list is NOT empty, sets the header's next to the referenced value of trailer, and the trailer's previous to the referenced value of header. 

Copy Assignment Operator: Allows the operator = to be used in order to copy doubly linked lists without causing any issues. 

Move Assignment Operator: Allows us to use the operator = in order to move a list to another (new or old) list. 

Destructor: Deletes all nodes and data in a linked list, sets header and trailer to point to each other. (Becomes empty)

The insert_before function first creates a new node (named newNode), and sets the given value (function parameter) as the object in this node. It then gets the given node, then the node before it, and it assigns the node before it's next pointer to the new node (given node is referred to as p in function, this is the node we want to use as reference and insert something before it). Then, it sets the reference node's previous (pointer) to point to the new node. 

The insert_after function works very similarily, and the only difference is the way of rearranging the pointers of the existing nodes in the list and the pointers of the new node.

The remove_after function creates a new node called (to delete) and it sets it to the parameter given in the function's next node (meaning if the function parameter is node p, the new node will be set to equal the node after p). Then, it sets the node after p's pointer to point to the new node's next. Finally, it sets the new node's next's previous to (dereferenced) p. 

The remove_before works very similarily to the remove_after, the only difference is where the new node's pointers are pointing to, and which node in the list is pointing to the new node. 

Finally, the output operator << was defined. First, it creates a new node and sets this node to point to the first item in a doubly linked list. This is used to start the iteration (in a loop, this will be the first element we look at), then it created another new node, pointing to the last element of a list. This is used to end the loop. Then a while loop is used to iterate through the list, and it exits only when the "current node" is equal to the trailer. Inside of the loop, each node's object (as we iterate though the list) is added to an ostream, and then the "current node" is updated. When the loop is done, the entire ostream is outputted (therefore all values that were in the list will be outputted). 



Only the last few functions had to be demoed in the main, so I added a few cout statements and each function one time to prove that they all work. 
---------------------------------------------------------------------------------------------------------

The program was tested using the Cygwin terminal and a make file that Professor Leyk provided. Once it was completed and tested, I used the Putty terminal to make sure that it would work on the TAs computer.

---------------------------------------------------------------------------------------------------------
I ran the program a total of 10 times once I completed it, to ensure that all functions worked properly, and that the program outputted the right information each time. All tests passed.




