#include <iostream>
#include <fstream>
#include <string>
#include "Stress_ball.h"
#include "Collection.h"

using namespace std;

using CollectionSB = Collection<Stress_ball, Stress_ball_colors,
                                Stress_ball_sizes>;

//CollectionSB specifies templated Collection
std::istream &operator>>(istream &is, CollectionSB &c)
{
  string line, sbColor, sbSize;
  Stress_ball_sizes sizes;
  Stress_ball_colors colors;
  int count = 1;
  while (getline(is, line))
  {
    count++;
    int len = 0;
    while (line[len] != ' ')
    {
      len++;
    }
    sbColor = line.substr(0, len);
    sbSize = line.substr(len + 1, line.size());

    if (sbColor == "red")
      colors = Stress_ball_colors::red;
    else if (sbColor == "yellow")
      colors = Stress_ball_colors::yellow;
    else if (sbColor == "blue")
      colors = Stress_ball_colors::blue;
    else
      colors = Stress_ball_colors::green;
    //Stress_ball_sizes sbSize = convertSize(str2);

    if (sbSize == "small")
      sizes = Stress_ball_sizes::small;
    else if (sbSize == "medium")
      sizes = Stress_ball_sizes::medium;
    else
      sizes = Stress_ball_sizes::large;

    Stress_ball add(colors, sizes);
    c.insert_item(add);
  }
  return is;
}

int main()
{
  cout << "---------------------------------------------------" << endl;
  cout << "Creating collection. " << endl;
  CollectionSB c1;
  string file = "stress_ball1.data";
  ifstream is(file);
  is >> c1;
  is.close();
  cout << "Collection created.\n"
       << endl;

  cout << "Creating collection. " << endl;
  file = "stress_ball2.data";
  CollectionSB c2;
  ifstream ifs(file);
  ifs >> c2;
  ifs.close();
  cout << "Collection created." << endl;
  cout << "---------------------------------------------------" << endl;

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
