README File for Assignment 1 - A Collection Class (part 1)

Alexia Perez, 127008512, CSCE 221-506, alexia_perezv, alexia_perezv@tamu.edu
---------------------------------------------------------------------------------------------------------
I certify that I have listed all the sources that I used to develop the solutions and code to the submitted work.
	On my honor as an Aggie, I have neither given nor received any unauthorized help on this academic work.
Alexia Perez
January 15th, 2020
---------------------------------------------------------------------------------------------------------
Aside from a few discussions with Peer Teachers, the only other outside resource I used was: https://es.cppreference.com/w/cpp/language/enum
I used this resource to learn how an enum class behaves and how to use it, as I never learned about these kinds of classes last semester in Professor Moore's 121 class.
---------------------------------------------------------------------------------------------------------
No issues found with the code submitted.
---------------------------------------------------------------------------------------------------------
The program: 
I separated my code into two different files (as it was required). In the Stress_ball.cpp file, I included all definitions for the functions needed in the assignment. In the Stress_ball.h file, I included all function and class declarations to be used for this assignment. 

Stress_ball.h:
I created two enum classes (Stress_ball_colors and Stress_ball_sizes) in which I defined the colors and sizes available for each "stress ball" created. The third class is the main class used in this assignment, the Stress_ball class. This class has 5 public functions, described below, and 2 private members (the size and color of each ball). The last function in the .h file is an overload operator that allows the program to print the desired output (each stress ball as a color and a size in parenthesis). Without this overload operator, there would be an error when trying to output the "stress balls" this way.

Stress_ball.cpp:
In the cpp file I included the definitions for all of the functions mentioned above. 
The first function is an overload operator that returns true when the stress ball given in the parameters is compared to the "this" stress ball and they are the same color and size. Otherwise it will return false.
The second function definition is a default "stress ball" constructor. It creates a new "stress ball" of random size and color. The color and size are randomized by using a random number generator and the fact that in enum classes each element is assigned a number. The function generates a number from 0 to the highest value in each of the 2 respective (enum) classes and based on the number it determines which color/size the new ball will be.
The next two functions simply return the color and size of a stress ball in order to be able to use them in the program, as these are private members of the stress ball class.
Lastly, an overload operator function (for operator <<) was defined that given a stress ball with a set color and size it prints the ball's color and size in the following format: (color,size)

Stress_ball_test.cpp:
This file was provided by Professor Leyk.

---------------------------------------------------------------------------------------------------------
The program was tested using the Cygwin terminal and the make file provided by Professor Leyk. Once it was completed and tested, I used the Putty terminal to make sure that it would work on the TAs computer.

---------------------------------------------------------------------------------------------------------
I ran the program a total of 15 times once I completed it, to ensure that my random number generators worked, and that the program outputted the right information each time. ALl tests passed.



