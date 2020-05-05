// Header file for Assignment 1 part 1.
#ifndef Stress_Ball_H
#define Stress_Ball_H

#include <iostream>

// Class definition for colors
enum class Stress_ball_colors
{
    red,
    blue,
    yellow,
    green
};

//Class definition for sizes
enum class Stress_ball_sizes
{
    small,
    medium,
    large
};

class Stress_ball
{
public:
    Stress_ball();
    Stress_ball(Stress_ball_colors c, Stress_ball_sizes s) : color(c), size(s) {}
    Stress_ball_colors get_color() const;
    Stress_ball_sizes get_size() const;
    bool operator==(const Stress_ball &sb);
private:
    Stress_ball_colors color;
    Stress_ball_sizes size;
};

std::ostream &operator<<(std::ostream& out, const Stress_ball& sb);

#endif