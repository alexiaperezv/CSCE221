#include <iostream>
#include "Jeans.h"


Jeans::Jeans(){
  int color_num = rand() % 4;
  color = Jeans_colors(color_num);
    
  int size_num = rand() % 3;
  size = Jeans_sizes(size_num);
}


Jeans::Jeans(Jeans_colors c, Jeans_sizes s){
    color = c;
    size = s;
}

Jeans_colors Jeans::get_color() const{
    return color;
}

Jeans_sizes Jeans::get_size() const{
    return size;
}

bool Jeans::operator==(const Jeans &jn){
  if(jn.color == this->color){
    if(jn.size == this->size){
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

std::ostream& operator<<(std::ostream& os, const Jeans& jn){
    std::string sizeOut, colorOut;
    switch(jn.get_color()){
        case Jeans_colors::white: colorOut = "white";
      break;
    case Jeans_colors::blue: colorOut = "blue";
      break;
    case Jeans_colors::black: colorOut = "black";
      break;
    case Jeans_colors::maroon: colorOut = "maroon";
      break;
    }
    switch(jn.get_size()){
    case Jeans_sizes::small: sizeOut = "small";
      break;
    case Jeans_sizes::medium: sizeOut = "medium";
      break;
    case Jeans_sizes::large: sizeOut = "large";
      break;
    case Jeans_sizes::xlarge: sizeOut = "xlarge";
      break;
    }
    os << "(" << colorOut << ":"<< sizeOut << ")" << std::endl;
    return os;
}

