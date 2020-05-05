#ifndef Stress_ball_h
#define Stress_ball_h
#include <stdio.h>
#include <string>

using namespace std;


enum class Stress_ball_colors{
  red, yellow, blue, green
    };

enum class Stress_ball_sizes{
  small = 0, medium = 1, large = 2
    };

class Stress_ball{
  Stress_ball_colors color;
  Stress_ball_sizes size;
 public:
  Stress_ball();
  Stress_ball(Stress_ball_colors c, Stress_ball_sizes s);
  bool operator==(const Stress_ball& sb);
        
  Stress_ball_colors get_color() const;
  Stress_ball_sizes get_size() const;
};

std::ostream& operator<<(std::ostream& o, const Stress_ball& sb);

#endif
