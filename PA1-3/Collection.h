#ifndef Collection_h
#define Collection_h
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "Stress_ball.h"
#include "Jeans.h"

template <class Obj, class F1, class F2>
class Collection
{
    Obj *array;   //pointer to dynamically allocated memory
    int size;     //number of elements in use
    int capacity; //physical size of array
    void resize()
    {
        if (capacity == 0)
        {
            array = new Obj[1];
            capacity = 1;
            return;
        }
        else if ((size + 1) > capacity)
        {
            int n = size + 1;
            Obj *newCollection = new Obj[n];
            for (int i = 0; i < size; i++)
            {
                newCollection[i] = array[i];
            }
            //no memory deletion
            capacity = 2 * n;
            return;
        }
        else
        {
            return;
        }
    }

public:
    Collection()
    {
        size = 0;
        capacity = 0;
        array = nullptr;
    }
    Collection(int s)
    {
        size = s, capacity = s * 2;
        array = new Obj[s];
    }
    Collection(const Collection &other)
    {
        array = new Obj[other.capacity];
        for (int i = 0; i < other.size; i++)
        {
            array[i] = other.array[i];
        }
        size = other.size;
        capacity = other.capacity;
    }
    Collection &operator=(const Collection &other)
    {
        if (&other == this)
        {
            return *this;
        }
        //std::cout << "Test7" << std::endl;
        //delete[] array;
        //std::cout << "Test8" << std::endl;
        array = new Obj[other.capacity];
        //std::cout << "Test9" << std::endl;
        for (int i = 0; i < other.size; i++)
        {
            array[i] = other.array[i];
        }
        //std::cout << "Test10" << std::endl;
        size = other.size;
        capacity = other.capacity;
        return *this;
    }

    Collection(Collection &&other)
    {
        size = other.size;
        capacity = other.capacity;
        array = new Obj[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = other.array[i];
        }
        //other.size = 0;
        //other.capacity = 0;
        //delete[] other.array;
        //other.array = nullptr;
    } //move constructor

    Collection& operator=(Collection &&other)
    {
        if (this != &other)
        {
            delete[] array;
            size = other.size;
            capacity = other.capacity;
            array = new Obj[size];
            for (int i = 0; i < size; i++)
            {
                array[i] = other.array[i];
            }
        }
        return *this;
    } //move assignmet operator

    ~Collection() { make_empty(); }

    void insert_item(const Obj &ob)
    {
        if (size == capacity)
        {
            resize();
        }
        array[size] = ob;
        size++;
    }
    void make_empty()
    {
        delete[] array;
        array = nullptr;
        size = 0;
        capacity = 0;
        return;
    }

    bool is_empty() const
    {
        if (size == 0)
            return true;
        else
            return false;
    }

    int total_items() { return size; }

    int total_items(F1 s) const
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
    int total_items(F2 t) const
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
    void print_items() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << array[i];
        }
    }

    Obj &operator[](int i) { return array[i]; }
    const Obj &operator[](int i) const { return array[i]; }
    int getSize() const { return size; }
};

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2> make_union(const Collection<Obj, F1, F2> &c1, const Collection<Obj, F1, F2> &c2)
{
    int size1 = c1.getSize();
    int size2 = c2.getSize();
    int total = size1 + size2;
    Collection<Obj, F1, F2> c3(total);
    for (int i = 0; i < size1; i++)
    {
        c3[i] = c1[i];
    }
    for (int j = 0; j < size2; j++)
    {
        c3[size1 + j] = c2[j];
    }
    return c3;
}

template <class Obj, class F1, class F2>
void swap(Collection<Obj, F1, F2> &c1, Collection<Obj, F1, F2> &c2)
{
    //c1.print_items();
    //std::cout << std::endl;
    //std::cout << "Test3" << std::endl;
    Collection<Obj, F1, F2> temp = c1;
    //temp.print_items();
    //std::cout << std::endl;
    //std::cout << "Test4" << std::endl;
    c1 = c2;
    //std::cout << "Test5" << std::endl;
    c2 = temp;
    //std::cout << "Test6" << std::endl;
    return;
    /*
    Collection<Obj, F1, F2> temporary1(c1);
    Collection<Obj, F1, F2> temporary2(c2);
    c1 = move(temporary2);
    c2 = move(temporary1);
    */
}

enum class Sort_choice
{
    bubble_sort,
    insertion_sort,
    selection_sort
};

template <class Obj, class F1, class F2>
void sort_by_size(Collection<Obj, F1, F2> &c, Sort_choice sort)
{

    switch (sort)
    {
    case Sort_choice::bubble_sort:
        for (int i = 0; i < c.getSize(); i++)
        {
            for (int j = 0; j < c.getSize() - i - 1; j++)
            {
                if (c[j].get_size() > c[j + 1].get_size())
                {
                    swap(c[j], c[j + 1]);
                }
            }
        }
        break;

    case Sort_choice::insertion_sort:
        int j;
        for (int i = 1; i < c.getSize(); i++)
        {
            j = i - 1;
            Obj curr = c[i];
            while (j >= 0 && (c[j].get_size() > curr.get_size()))
            {
                c[j + 1] = c[j];
                j = j - 1;
            }
            c[j + 1] = curr;
        }
        break;

    case Sort_choice::selection_sort:
        int minPosition;
        for (int i = 0; i < c.getSize() - 1; i++)
        {
            minPosition = i;
            for (int j = i + 1; j < c.getSize(); j++)
            {
                if (c[j].get_size() < c[minPosition].get_size())
                {
                    minPosition = j;
                }
            }
            if (minPosition != i)
            {
                Obj temp = c[i];
                c[i] = c[minPosition];
                c[minPosition] = temp;
            }
        }
        break;
    }
};
#endif
