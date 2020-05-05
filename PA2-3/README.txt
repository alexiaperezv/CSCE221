README File for Assignment PA2-3 

Alexia Perez, 127008512, CSCE 221-506, alexia_perezv, alexia_perezv@tamu.edu
---------------------------------------------------------------------------------------------------------
I certify that I have listed all the sources that I used to develop the solutions and code to the submitted work.
	On my honor as an Aggie, I have neither given nor received any unauthorized help on this academic work.
Alexia Perez
March 6th, 2020
---------------------------------------------------------------------------------------------------------
The only other outside resource I used was: 

https://www.geeksforgeeks.org/

I used this resource to read documentation about the use of MinQueues and some other small
details such as definitons for the different types of functions and their use, etc.
 
---------------------------------------------------------------------------------------------------------
No issues found with the code submitted.
---------------------------------------------------------------------------------------------------------
The program: 

I created 2 files for this assignment and used one from part two (the templated DLL). 

In the MinQueue.h file I simply created the MinQueue class and declared & defined all the functions that the assignment required me to create.  

Functions: 

MinQueue(): default constructor that creates a new MinQueue with size 0. 

int get_size(): returns the size of the MinQueue (because size is a private element).

bool is_empty(): returns true if size = 0, returns false otherwise. 

DLList<T> &print(): uses the DLL Templated class from part 2, prints the queue.

void enqueue(T obj): uses the DLL Templated class from part 2, and inserts obj as the last position in the queue, increases size of MinQueue by one. 

T dequeue(): if the MinQueue is empty, it throws an error, otherwise it creates a value of type T and it removes the last element in the queue, then sets the variable "value" to the value of the element that was just removed from the queue. Decreases size by one and returns the variable "value."

T min(): Checks if queue is empty, if so, throws error message. If not empty, it sets the queue's minimum to the queue's first value, then uses a for loop to traverse through the entire queue and compares the min to every value, changing min only if there is a value that is smaller. Once the for loop is done, it returns the minimum. This is the only function that is not O(1) because it uses a for loop, which is O(n).

The MinQueue.cpp file includes the main(). I separated this file into "blocks" and tested the MinQueue functions in order. I indicated what each "block" of code does by using comments. In this file, I test all of the functions defined in the .h file to ensure they work correctly.

The first block creates two empty MinQueues, then prints the first one. This is a test for the constructor. 

The second block tests the enqueue function. It uses a for loop to enqueue numbers 0-9. 

The third block copies MinQueue 1 to MinQueue 3. Then it sets MinQueue 2 to equal MinQueue 1 (copy assignment). Finally, it prints Queue 1. Copy assingment operator and Copy Constructor are tested here. 

The fourth block outputs the minimum value in Queue 1. This is a test for min().

The fifth block tests the dequeue function by dequeuing 3 items from Queue 1 and printing Queue 1 so the difference can be observed. It then finds the new minimum in Queue 1. 

The sixth block enqueues values form 10 to 0 in descending order into Queue 1. It then prints Queue 1 and again returns the new minimum. 

The seventh block dequeues the entire queue 1. 

The eighth block ensures that after manipulating Queue 1 this many times, Queue 2 and 3 were unaffected. 

The ninth block was created to aid in the visualization of Queue 2 v. Queue 3, it essentially makes them different from each other and then outputs both of them for the user to see that they are different. 

The tenth and last block tests the move constructor from the DLL Templated Class file. It creates a temporary MinQueue called temp, and it moves all items from queue 2 to temp. Then it moves all items from queue 3 to queue 2, and finally moves all items from temp to queue 3. This causes queue 2 and queue 3 to swap. It then outputs both queue 2 and queue 3. 

I outputted the message "Code finished" at the end of my code for testing purposes, and it still outputs eery time the code is ran. This is for me to see that every line was executed correctly (with no errors and no memory leaks).


---------------------------------------------------------------------------------------------------------

The program was tested using the Cygwin terminal and a make file that I created. Once it was completed and tested, I used the Putty terminal to make sure that it would work on the TAs computer.

---------------------------------------------------------------------------------------------------------
I ran the program a total of 10 times once I completed it, to ensure that all functions worked properly, and that the program outputted the right information each time. All tests passed.




