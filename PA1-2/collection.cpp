// DEFINITIONS OF COLLECTION CLASS FUNCTIONS
#include "collection.h"
#include <iostream>
#include <fstream>
using namespace std;

Collection::Collection()
{
    size = 0;
    capacity = 0;
    array = nullptr;
};

Collection::Collection(int s)
{
    size = 0;
    capacity = s;
    array = new Stress_ball[s];
}

Collection::Collection(const Collection &original_Collection)
{
    capacity = original_Collection.capacity;
    size = original_Collection.size;
    array = new Stress_ball[size];
    for (int i = 0; i < original_Collection.size; i++)
    {
        array[i] = original_Collection[i];
    } //copies array of stress balls
}

Collection &Collection::operator=(const Collection &original_Collection)
{
    size = original_Collection.size;
    capacity = original_Collection.capacity;
    array = new Stress_ball[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = original_Collection.array[i];
    }
    return *this;
}

Collection::~Collection()
{
    delete[] array;
}

Collection::Collection(Collection &&other)
{
    size = other.size;
    capacity = other.capacity;
    array = new Stress_ball[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = other.array[i];
    }
    other.size = 0;
    other.capacity = 0;
    delete[] other.array;
    other.array = nullptr;
} //move constructor

Collection &Collection::operator=(Collection &&other)
{
    if (this != &other)
    {
        delete[] array;
        size = other.size;
        capacity = other.capacity;
        array = new Stress_ball[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = other.array[i];
        }
        other.array = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
} //move assignmet operator

// FUNCTIONS
void Collection::insert_item(const Stress_ball &sb)
{
    //at last index, which would be = to size
    if (size < capacity)
    {
        array[size] = sb;
        size++;
    }
    else
    {
        resize();
        array[size] = sb;
        size++;
    }
}
void Collection::resize()
{
    int new_Size = size;
    int new_Capacity;
    if (capacity == 0)
        new_Capacity = 1;
    else
        new_Capacity = capacity * 2;
    Stress_ball *new_Array = new Stress_ball[new_Capacity];
    for (int i = 0; i < size; i++)
    {
        new_Array[i] = array[i];
    }
    delete[] array;
    array = new_Array;
    size = new_Size;
    capacity = new_Capacity;
}

bool Collection::contains(const Stress_ball &sb) const
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == sb)
        {
            return true;
        }
    }
    return false;
}

Stress_ball Collection::remove_any_item()
{
    if (array == nullptr)
    {
        throw "EXCEPTION: Colection empty. No items to be removed.";
    }
    int random = rand() % size;
    Stress_ball random_Ball = array[random];
    for (int t = random; t < size - 1; t++)
    {
        array[t] = array[t + 1];
    }
    size--;
    return random_Ball;
}

void Collection::remove_this_item(const Stress_ball &sb)
{
    if (array == nullptr)
    {
        throw "EXCEPTION: Colection empty. No items to be removed.";
    }
    int random = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == sb)
        {
            random = i;
            break;
        }
    }
    Stress_ball random_Ball = array[random];
    for (int t = random; t < size - 1; t++)
    {
        array[t] = array[t + 1];
    }
    size--;
}
void Collection::make_empty()
{
    size = 0;
    capacity = 0;
    delete[] array;
    array = nullptr;
}

bool Collection::is_empty() const
{
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Collection::total_items() const
{
    return size;
}

int Collection::total_items(Stress_ball_sizes s) const
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i].get_size() == s)
        {
            counter++;
        }
    }
    return counter;
}
int Collection::total_items(Stress_ball_colors t) const
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i].get_color() == t)
        {
            counter++;
        }
    }
    return counter;
}
void Collection::print_items() const
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}

//OPERATOR OVERLOAD
Stress_ball &Collection::operator[](int i)
{
    if (i >= size)
    {
        throw "EXCEPTION: Array index out of bound.";
    }
    return array[i];
}
const Stress_ball &Collection::operator[](int i) const
{
    if (i >= size)
    {
        throw "EXCEPTION: Array index out of bound.";
    }
    return array[i];
}

// Functions to manipulate class
istream &operator>>(istream &is, Collection &c)
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

ostream &operator<<(ostream &os, const Collection &c)
{
    // go thru every object in the collection
    for (int i = 0; i < c.total_items(); i++)
    {
        os << c[i] << endl;
    } // makes a long stream of stress balls, and then outputs this stream
    return os;
}

Collection make_union(const Collection &c1, const Collection &c2)
{
    Collection combined;
    for (int i = 0; i < c1.total_items(); i++)
    {
        combined.insert_item(c1[i]);
    }
    for (int i = 0; i < c2.total_items(); i++)
    {
        combined.insert_item(c2[i]);
    }
    return combined;
}

void swap(Collection &c1, Collection &c2)
{
    Collection temporary1(c1);
    Collection temporary2(c2);
    c1 = move(temporary2);
    c2 = move(temporary1);
}

void sort_by_size(Collection &c, Sort_choice sort)
{
    int size = c.total_items();
    Stress_ball temp;
    switch (sort)
    {
    case Sort_choice::bubble_sort:
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (c[j].get_size() > c[j + 1].get_size())
                {
                    temp = c[j];
                    c[j] = c[j + 1];
                    c[j + 1] = temp;
                }
            }
        }
        break;
    case Sort_choice::insertion_sort:
        Stress_ball_sizes key;
        int q;
        int p;
        for (int q = 1; q < size; q++)
        {
            key = c[q].get_size();
            temp = c[q];
            p = q - 1;
            while (p >= 0 && c[p].get_size() > key)
            {
                c[p + 1] = c[p];
                p = p - 1;
            }
            c[p + 1] = temp; //the stress ball whose size is represented by key;
        }
        break;
    case Sort_choice::selection_sort:
        int i;
        int j;
        int min_Index;
        for (i = 0; i < size - 1; i++)
        {
            min_Index = i;
            for (j = i + 1; j < size; j++)
                if (c[j].get_size() < c[min_Index].get_size())
                    min_Index = j;
            Stress_ball swap = c[min_Index];
            c[min_Index] = c[i];
            c[i] = swap;
        }
        break;
    }   
}