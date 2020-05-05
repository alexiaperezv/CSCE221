#include <iostream>
#include "Stress_ball.h"

//default constructor
Stress_ball::Stress_ball(){
  int color_num = rand() % 4;
  color = Stress_ball_colors(color_num);
    
  int size_num = rand() % 3;
  size = Stress_ball_sizes(size_num);
}
   
//parametrized constructor
Stress_ball::Stress_ball(Stress_ball_colors c, Stress_ball_sizes s){
  color = c;
  size = s;
}

Stress_ball_colors Stress_ball::get_color() const{
  return color;
}

Stress_ball_sizes Stress_ball::get_size() const {
  return size;
}


bool Stress_ball::operator==(const Stress_ball &sb){
  if(sb.color == this->color){
    if(sb.size == this->size){
      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
}


std::ostream& operator<<(std::ostream& os, const Stress_ball &sb){
  std::string sizeOut, colorOut;
  switch(sb.get_color()){
  case Stress_ball_colors::red: colorOut = "red";
    break;
  case Stress_ball_colors::yellow: colorOut = "yellow";
    break;
  case Stress_ball_colors::blue: colorOut = "blue";
    break;
  case Stress_ball_colors::green: colorOut = "green";
    break;
  }
  switch(sb.get_size()){
  case Stress_ball_sizes::small: sizeOut = "small";
    break;
  case Stress_ball_sizes::medium: sizeOut = "medium";
    break;
  case Stress_ball_sizes::large: sizeOut = "large";
    break;
  }
  os << "(" << colorOut << ":"<< sizeOut << ")" << std::endl;
  return os;

}

