// cpp file for Assignment 1 part 1.
#include "Stress_ball.h"
#include <iostream>
using namespace std;

bool Stress_ball::operator==(const Stress_ball &sb)
{
    if (this->color == sb.color && this->size == sb.size)
        return true;
    else
        return false;
}

// Constructor definitions
Stress_ball::Stress_ball()
{

    int x = rand() % 4;
    int y = rand() % 3;

    // color
    switch (x)
    {
    case 0:
        color = Stress_ball_colors::red;
        break;
    case 1:
        color = Stress_ball_colors::blue;
        break;
    case 2:
        color = Stress_ball_colors::yellow;
        break;
    case 3:
        color = Stress_ball_colors::green;
        break;
    }

    // size
    switch (y)
    {
    case 0:
        size = Stress_ball_sizes::small;
        break;
    case 1:
        size = Stress_ball_sizes::medium;
        break;
    case 2:
        size = Stress_ball_sizes::large;
        break;
    }
}

// Get color and size function defintions
Stress_ball_colors Stress_ball::get_color() const
{
    return color;
}

Stress_ball_sizes Stress_ball::get_size() const
{
    return size;
}

// Overload operator
ostream &operator<<(ostream &o, const Stress_ball &sb)
{

    switch (sb.get_color())
    {
    case Stress_ball_colors::red:
        o << "(red,";
        break;
    case Stress_ball_colors::blue:
        o << "(blue,";
        break;
    case Stress_ball_colors::yellow:
        o << "(yellow,";
        break;
    case Stress_ball_colors::green:
        o << "(green,";
        break;
    }
    switch (sb.get_size())
    {
    case Stress_ball_sizes::small:
        o << "small)";
        break;
    case Stress_ball_sizes::medium:
        o << "medium)";
        break;
    case Stress_ball_sizes::large:
        o << "large)";
        break;
    }

    return o;
}