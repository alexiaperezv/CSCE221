// Code for PA2-3 MinQueue
#include "MinQueue.h"
#include <iostream>

using namespace std;

int main()
{
    // BLOCK 1: Test for constructor using int as data type
    cout << "Creating empty int queues..." << endl;
    MinQueue<int> q, q2;
    cout << "Queue 1: " << q.print() << endl
         << endl;

    // BLOCK 2: Test for enqueue
    cout << "Enqueueing 0-9 (to Queue 1)..." << endl;
    for (int i = 0; i < 10; i++)
        q.enqueue(i);

    // BLOCK 3: Test for Copy Constructor and Copy Assignment

    cout << "Copying Queue 1 into new queue (queue 3)..." << endl
         << endl;
    MinQueue<int> q3(q);
    q2 = q;
    cout << "Queue 1: " << q.print() << endl
         << endl;

    // BLOCK 4: Test for min function
    cout << "Queue 1 current min: " << q.min() << endl
         << endl;

    // BLOCK 5: Test for dequeue
    cout << "Dequeueing 3 items from Queue 1..." << endl;
    for (int i = 0; i < 3; i++)
        cout << q.dequeue() << " ";
    cout << endl
         << "Queue: " << q.print() << endl;

    // Find min again (part of Block 5)
    cout << "New current min: " << q.min() << endl
         << endl;

    // BLOCK 6: Enqueue values 10 to 0 in descending order
    cout << "Enqueing 10-0..." << endl;
    for (int i = 10; i >= 0; i--)
        q.enqueue(i);
    cout << endl
         << "Queue 1: " << q.print() << endl;
    // Find new min
    cout << "New current min: " << q.min() << endl
         << endl;

    // BLOCK 7: Test to dequeue entire queue
    cout << "Dequeueing entire Queue 1..." << endl;
    while (!q.is_empty())
        cout << q.dequeue() << " ";
    cout << endl;

    // BLOCK 8: Test that other queues are NOT affected after manipulating Queue 1
    cout << "Checking that q2 and q3 aren't affected..." << endl;
    cout << "Q2: " << q2.print() << endl;
    cout << "Q3: " << q3.print() << endl
         << endl;

    // BLOCK 9: For ease of visualization, make q2 and q3 different from each other
    cout << "Manipulating q2 and q3 to make them different from each other..." << endl;
    q2.enqueue(100000);
    q3.dequeue();
    cout << "Q2: " << q2.print() << endl;
    cout << "Q3: " << q3.print() << endl
         << endl;

    // BLOCK 10: Test swap function
    cout << "Swapping queues..." << endl;
    MinQueue<int> temp(move(q2));
    q2 = move(q3);
    q3 = move(temp);
    cout << "Q2: " << q2.print() << endl;
    cout << "Q3: " << q3.print() << endl
         << endl;
    cout << "Code finished." << endl;
}