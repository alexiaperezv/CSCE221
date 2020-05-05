#include "graph.h"
#include <iostream>
#include <vector>

using namespace std;

Graph::~Graph() // Graph Data Structure Destructor
{
    for (const auto edges : adj_list)
    {
        delete edges;
    }
};

// Destructor Explanation (for later use in Report)
// for-loop with range "edges" (automatic type variable).
// meaning: during every iteration, an element from adj_list is "copied" into auto variable "edges"
// since every element is copied into edges, the loop will delete all elements one by one.


void Graph::buildGraph(ifstream &input) // builds graph
{
    string line;
    string lineProcessing;
    list<int> vertexStorage;
    list<int> *vertexPush;

    while (getline(input, line, '\n')) 
    {
        stringstream inputStorage(line);
        inputStorage >> lineProcessing;
        if (lineProcessing == "-1")
        {
            break;
        }
        Vertex edge(stoi(lineProcessing));
        while (lineProcessing != "-1")
        {
            inputStorage >> lineProcessing;
            if (lineProcessing != "-1")
            {
                vertexStorage.push_back(stoi(lineProcessing));
            }
        }
        vertexPush = new list<int>(vertexStorage);
        node_list.push_back(edge);
        adj_list.push_back(vertexPush);
        vertexStorage.clear();
    }
};

// Build Graph Explanation (for later use in Report):
// While-loop runs as long as there is a new line in the file.
// Basically parses through file line-by-line, storing the lines in variable "line" through every iteration.
// We store the line in a stringstream
// then we "enter" the stringstream into a new string called "line processing"
// if we process the line using lineProcessing and we get that it is a -1, we break from loop.
// otherwise we will keep going inside the loop
// we now create a new Vertex object, called edge, and set it to the integer value of the line we just processed
// then we enter a new while-loop that runs as long as our line processing does not equal -1
// this loop will basically parse through the line to find each "number" associated with the vertex
// if the number is NOT a -1, we will add it into the Vertex Storage list
// once we are done with processing the whole line we stop the small (second) while loop
// after entire line is processed, we first create a list that will store our whole 
// vertexStorage list within it as a single element
// then we store our found edge to the list of nodes
// we store the vertex push list into our adjacent list
// once we do this for all lines in the file, we are done.

void Graph::displayGraph() // displays graph
{
    for (int i = 0; i < node_list.size(); i++)
    {
        cout << node_list[i].label << ": ";
        for (const auto edges : *adj_list[i])
        {
            cout << edges << " ";
        }
        cout << endl;
    }
};

// Display Graph Explanation (for later use in Report):
// for-loop iterates through the node list
// at every node in the list, it displays its "label"
// then a for-loop iterates through that node's adjacent list
// outputs all edges in the adjacent list for the node separated by a space
// after all this is done, we output an extra line (endl).