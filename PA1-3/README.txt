README File for Assignment 1 - A Collection Class (part 2)

Alexia Perez, 127008512, CSCE 221-506, alexia_perezv, alexia_perezv@tamu.edu
---------------------------------------------------------------------------------------------------------
I certify that I have listed all the sources that I used to develop the solutions and code to the submitted work.
	On my honor as an Aggie, I have neither given nor received any unauthorized help on this academic work.
Alexia Perez
January 29th, 2020
---------------------------------------------------------------------------------------------------------
Aside from a few discussions with Peer Teachers, the only other outside resource I used was: 
https://www.geeksforgeeks.org/
I used this resource to read documentation about the use of the move constructor and some other small
details such as definitons for the different types of sorting algorithms, etc.
---------------------------------------------------------------------------------------------------------
No issues found with the code submitted.
---------------------------------------------------------------------------------------------------------
The program: 
I created 3 new files for this part in addition to the Stress_ball files created in the first part of the assignment.

collection.h:
In this file I defined the Collection class and all of its private members and public functions. 
I created the public functions following the instructions given to me by Dr. Leyk via ecampus. I found the functions that were part of the Collection class very clear and straight forward to code. The collection class and its member functions were demonstrated to my TA last week. No isses found so far.

As for the functions that were not part of the Collection class: 
There were only 5 functions outside of the Collection class.
*input operator overload: allows us to use the operator << to read an element from a collection (given in a text file).
*output operator overload: allows us to use the operator >> to cout a collection.
*swap function: swaps two collections
*union function: merges two collections into one. According to Piazza, the union collection simply combines two collections, allowing for duplicates.
*sort function: uses a switch case to determine what kind of sorting algorithm to use, then uses the selected algorithm to sort the collection by stress ball size from smallest to largest.

collection.cpp:
In the cpp file I included the definitions for all of the functions mentioned above. I believe all of them were very straight forward, but the input/output operators are worth being mentioned since they took me the longest to figure out. The sort function itself was easy, but the 3 different methods of sorting collections took a little bit to figure out. I references "GeeksforGeeks.org" to help me understand the difference between each method and be able to implement it in my code. 

The input operator: similar to the output operator overload from the Stress_ball.cpp, it determines the color of a stress_ball by reading the first word in the input file (text file) using if-else statements and stores this color in a variable, then it determines the size (second word) and stores it in a variable.
It thencreates a new element "Stress_ball" using these two parameters in the constructor. After this, it inserts the new ball into a collection. This is how we read the stress ball from one file and store them inside of a single collection.

The output operator: this operator was much easier to code than the input one, partly because I have more experience overloading output operators. It uses a for-loop to read every single stress ball in a collection, loads it into the output stream, then returns the output stream. This allows us to use the << operator to cout an entire collection. 

collection_test.cpp:
This file was created to test the functions written in the previous two files. It includes a test for every requirement in the instructions.
It is very straight forward and only uses functions created in the collection.cpp

---------------------------------------------------------------------------------------------------------
The program was tested using the Cygwin terminal and a make file that I created based on the makefile that Professor Leyk provided for the first part of the assignment. Once it was completed and tested, I used the Putty terminal to make sure that it would work on the TAs computer.

---------------------------------------------------------------------------------------------------------
I ran the program a total of 10 times once I completed it, to ensure that all functions worked properly, and that the program outputted the right information each time. All tests passed.




