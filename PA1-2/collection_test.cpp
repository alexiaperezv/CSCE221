// TEST FILE FOR COLLECTION CLASS
#include <iostream>
#include "collection.h"
#include <string>

using namespace std;

main()
{

    // Test file requirement b:
    Collection collection_one;
    Collection collection_two;

    for (int i = 0; i < 2; i++)
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
                file >> collection_one;
            if (i == 1)
                file >> collection_two;
        }
        file.close();
    }

    // Test file requirement c:
    cout << "There are: " << collection_one.total_items(Stress_ball_colors::green) << " items in Collection One that are Green." << endl;
    cout << "There are: " << collection_two.total_items(Stress_ball_colors::blue) << " items in Collection Two that are Blue." << endl;
    cout << "There are: " << collection_one.total_items() << " total items in Collection One." << endl;
    cout << "There are: " << collection_two.total_items() << " total items in Collection Two." << endl;
    cout << endl;

    // Test file requirement d:
    Collection new_Collection = make_union(collection_two, collection_one);
    cout << "Union Collection: " << endl;
    new_Collection.print_items();
    cout << endl;
    // Count how many medium green stress balls are in the union collection:
    int repeats;
    for (int i = 0; i < new_Collection.total_items(); i++)
    {
        if (new_Collection[i].get_color() == Stress_ball_colors::green && new_Collection[i].get_size() == Stress_ball_sizes::medium)
        {
            repeats++;
        }
    }
    cout << "There are: " << repeats << " medium green stress balls in the Union Collection." << endl;
    cout << "There are: " << new_Collection.total_items() << " total stress balls in the Union Collection." << endl;
    cout << endl;

    // Test file requirement e:
    cout << "Swapping collections 1 and 2..." << endl;
    swap(collection_one, collection_two);
    cout << "Collection 1 is now: " << endl;
    cout << "Items: " << collection_one.total_items() << endl;
    collection_one.print_items();
    cout << endl;
    cout << "Collection 2 is now: " << endl;
    cout << "Items: " << collection_two.total_items() << endl;
    collection_two.print_items();
    cout << endl;

    // Test file requirement f:

    cout << "Sorting Collection 1..." << endl;
    cout << endl;

    cout << endl
         << "Bubble:" << endl;
    sort_by_size(collection_one, Sort_choice::bubble_sort);
    collection_one.print_items();
    cout << endl;

    cout << endl
         << "Insertion:" << endl;
    sort_by_size(collection_one, Sort_choice::insertion_sort);
    collection_one.print_items();
    cout << endl;

    cout << endl
         << "Selection:" << endl;
    sort_by_size(collection_one, Sort_choice::selection_sort);
    collection_one.print_items();
    cout << endl;

    cout << endl
         << "\t\t\tNetflix & Chill? ;) " << endl;
}