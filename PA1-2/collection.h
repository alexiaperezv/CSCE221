// HEADER FILE FOR COLLECTION CLASS
#ifndef collection_H
#define collection_H

#include <iostream>
#include <fstream>
#include "Stress_ball.h"
using std::ostream;
using std::istream;

// Collection class definition
class Collection 
{
    private: 
        Stress_ball *array;
        int size; //number of elements in use (in the array)
        int capacity; // size of the array
    public: 
        Collection(); //Default constructor
        Collection(int s); //Constructor
        Collection(const Collection &original_Collection); //copy constructor
        Collection& operator=(const Collection& original_Collection); // copy assignment
        ~Collection(); // destructor
        Collection(Collection&& other); //move constructor
        Collection& operator=(Collection&& other); //move assignmet operator


        // FUNCTIONS
        void insert_item(const Stress_ball& sb);
        void resize();
        bool contains(const Stress_ball& sb) const;
        Stress_ball remove_any_item();
        void remove_this_item(const Stress_ball& sb);
        void make_empty();
        bool is_empty() const;
        int total_items() const;
        int total_items(Stress_ball_sizes s) const;
        int total_items(Stress_ball_colors t) const;
        void print_items() const;

        //OPERATOR OVERLOAD
        Stress_ball& operator[](int i);
        const Stress_ball& operator[](int i) const;
};

// Functions to manipulate classes 

enum class Sort_choice 
{
    bubble_sort,
    insertion_sort,
    selection_sort
};

istream& operator>>(istream& is, Collection& c);
ostream& operator<<(ostream& os, const Collection& c);
Collection make_union(const Collection& c1, const Collection& c2);
void swap(Collection& c1, Collection& c2);
void sort_by_size(Collection& c, Sort_choice sort);
#endif