#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Collection.h"
#include "Jeans.h"

using namespace std;

using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;

//input operator
std::istream& operator>>(istream& is, CollectionJN& c){
    string line, jnColor, jnSize;
    Jeans_sizes size;
    Jeans_colors color;
    int count = 1;
        while(getline(is,line)){
            count++;
            int len = 0;
            while(line[len] != ' '){
                len++;
            }
            jnColor = line.substr(0,len);
            jnSize = line.substr(len+1, line.size());

            
            if(jnColor== "white") color = Jeans_colors::white;
            else if(jnColor == "blue") color = Jeans_colors::blue;
                else if(jnColor == "black") color = Jeans_colors::black;
            else color = Jeans_colors::maroon;
            //Stress_ball_sizes sbSize = convertSize(str2);
            
            if(jnSize == "small") size = Jeans_sizes::small;
            else if(jnSize == "medium") size = Jeans_sizes::medium;
                else if(jnSize == "large") size = Jeans_sizes::large;
            else size = Jeans_sizes::xlarge;

            Jeans add(color, size);
            c.insert_item(add);
        }
    return is;
}

int main(){
    cout << "---------------------------------------------------" << endl;
    cout << "Creating collection. " << endl;
    CollectionJN c1;
    string file = "jeans1.txt";
    ifstream is(file);
    is >> c1;
    is.close();
    c1.print_items();
    cout << "Collection created.\n" << endl;

    cout << "Creating collection. " << endl;
    file = "jeans2.txt";
    CollectionJN c2;
    ifstream ifs(file);
    ifs >> c2;
    ifs.close();
    c2.print_items();
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
    sort_by_size(c1,Sort_choice::bubble_sort);
    cout << "\nCollection 1: " << endl;
    c1.print_items();
    cout << "\nCollection 2: " << endl;
    sort_by_size(c2, Sort_choice::insertion_sort);
    c2.print_items();
    cout << "---------------------------------------------------" << endl;
    
    //Create a Union Collection
    CollectionJN c3 = make_union(c1, c2);
    cout << "Creating union Collection" << endl;
    c3.print_items();       //Print elements.
    cout << "---------------------------------------------------" << endl;
    
    //Creating a Copy of a Collection
    CollectionJN c4 = c2;
    cout << "Called copy constructor: Collection c2 copied to c4." << endl;
    c4.print_items();
    cout << "Code Finished." << endl;
    
    return 0;
}
