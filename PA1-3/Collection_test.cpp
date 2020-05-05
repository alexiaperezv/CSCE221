#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "Stress_ball.h"
#include "Collection.h"
#include "Jeans.h"

using namespace std;
using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;
using CollectionSB = Collection<Stress_ball, Stress_ball_colors,
                                Stress_ball_sizes>;

//input operator for Jean Collection
istream &operator>>(istream &is, CollectionJN &c)
{
    string cr, s;
    is >> cr >> s;
    Jeans_colors color;
    Jeans_sizes size;
    // color
    if (cr.compare("white") == 0)
        color = Jeans_colors::white;
    else if (cr.compare("blue") == 0)
        color = Jeans_colors::blue;
        
    else if (cr.compare("black") == 0)
        color = Jeans_colors::black;
    else if (cr.compare("maroon") == 0)
        color = Jeans_colors::maroon;
    else
        cout << "Error: Invalid Input" << endl;

    // size
    if (s.compare("small") == 0)
        size = Jeans_sizes::small;
    else if (s.compare("medium") == 0)
        size = Jeans_sizes::medium;
    else if (s.compare("large") == 0)
        size = Jeans_sizes::large;
    else if (s.compare("xlarge") == 0)
        size = Jeans_sizes::xlarge;
    else
        cout << "Error: Invalid Input" << endl;
    Jeans sb(color, size);
    c.insert_item(sb);

    return is;
}

//CollectionSB specifies templated Collection
istream &operator>>(istream &is, CollectionSB &c)
{
    string cr, s;
    is >> cr >> s;
    Stress_ball_colors color;
    Stress_ball_sizes size;
    // color
    if (cr.compare("red") == 0)
        color = Stress_ball_colors::red;
    else if (cr.compare("blue") == 0)
        color = Stress_ball_colors::blue;
    else if (cr.compare("yellow") == 0)
        color = Stress_ball_colors::yellow;
    else if (cr.compare("green") == 0)
        color = Stress_ball_colors::green;
    else
        cout << "Error: Invalid Input" << endl;

    // size
    if (s.compare("small") == 0)
        size = Stress_ball_sizes::small;
    else if (s.compare("medium") == 0)
        size = Stress_ball_sizes::medium;
    else if (s.compare("large") == 0)
        size = Stress_ball_sizes::large;
    else
        cout << "Error: Invalid Input" << endl;
    Stress_ball sb(color, size);
    c.insert_item(sb);

    return is;
}

void test_stress_balls()
{
    cout << "---------------------------------------------------" << endl;
    cout << "Creating collection. " << endl;
    CollectionSB c1;
    CollectionSB c2;
    for (int i = 0; i <= 1; i++)
    {
        ifstream file;
        if (i == 0)
            file.open("stress_ball1.txt");
        if (i == 1)
            file.open("stress_ball2.txt");
        if (!file.is_open())
        {
            throw "EXCEPTION: Unable to open file.";
        }
        while (!file.eof())
        {
            if (i == 0)
                file >> c1;
            if (i == 1)
                file >> c2;
        }
        file.close();
    }

    //Swap the two collections
    cout << "Collection 1: " << endl;
    c1.print_items();
    cout << "\nCollection 2: " << endl;
    c2.print_items();
    swap(c1, c2);
    cout << "\nCollection 1 after swap: " << endl;
    c1.print_items();
    cout << "\nCollection 2 after swap: " << endl;
    c2.print_items();
    cout << "---------------------------------------------------" << endl;

    //Sort by size for both Collections
    cout << "Sorting collection." << endl;
    sort_by_size(c1, Sort_choice::bubble_sort);
    cout << "\nCollection 1: " << endl;
    c1.print_items();
    cout << "\nCollection 2: " << endl;
    sort_by_size(c2, Sort_choice::insertion_sort);
    c2.print_items();
    cout << "---------------------------------------------------" << endl;

    //Create a Union Collection
    CollectionSB c3 = make_union(c1, c2);
    cout << "Creating union Collection" << endl;
    c3.print_items(); //Print elements.
    cout << "---------------------------------------------------" << endl;

    //Creating a Copy of a Collection
    CollectionSB c4 = c2;
    cout << "Called copy constructor: Collection c2 copied to c4." << endl;
    c4.print_items();
    cout << "Code Finished." << endl;
}

void test_jeans()
{
    cout << "---------------------------------------------------" << endl;
    cout << "Creating collection. " << endl;
    CollectionJN c1;
    CollectionJN c2;
    for (int i = 0; i <= 1; i++)
    {
        ifstream file;
        if (i == 0)
            file.open("jeans1.txt");
        if (i == 1)
            file.open("jeans2.txt");
        if (!file.is_open())
        {
            throw "EXCEPTION: Unable to open file.";
        }
        while (!file.eof())
        {
            if (i == 0)
                file >> c1;
            if (i == 1)
                file >> c2;
        }
        file.close();
    }

    //Swap the two collections
    cout << "Collection 1: " << endl;
    c1.print_items();
    cout << "\nCollection 2: " << endl;
    c2.print_items();
    swap(c1, c2);
    cout << "\nCollection 1 after swap: " << endl;
    c1.print_items();
    cout << "\nCollection 2 after swap: " << endl;
    c2.print_items();
    cout << "---------------------------------------------------" << endl;

    //Sort by size for both Collections
    cout << "Sorting collection." << endl;
    sort_by_size(c1, Sort_choice::bubble_sort);
    cout << "\nCollection 1: " << endl;
    c1.print_items();
    cout << "\nCollection 2: " << endl;
    sort_by_size(c2, Sort_choice::insertion_sort);
    c2.print_items();
    cout << "---------------------------------------------------" << endl;

    //Create a Union Collection
    CollectionJN c3 = make_union(c1, c2);
    cout << "Creating union Collection" << endl;
    c3.print_items(); //Print elements.
    cout << "---------------------------------------------------" << endl;

    //Creating a Copy of a Collection
    CollectionJN c4 = c2;
    cout << "Called copy constructor: Collection c2 copied to c4." << endl;
    c4.print_items();
    cout << "Code Finished." << endl;
}

int main()
{
    int answer;
    cout << "What version to test: stress_ball (=0) or jeans (=1): ";
    cin >> answer;
    if (answer == 0)
        test_stress_balls();
    else if (answer == 1)
        test_jeans();
    else
        cout << "Wrong value: " << answer << endl;
    return 0;
}
