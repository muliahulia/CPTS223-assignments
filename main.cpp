/*
using your understanding of design choices, software principles, and
coding standards, which we will group under the general label “attributes” — list and describe 5
attributes demonstrated by the code that you would consider poor. They should NOT be related
to the syntax errors. Examples of poor attributes could be related to comments, file structure,
data structure selection, algorithm efficiency, etc. Place your list in a comment block at the top
of the “main.cpp” file.

"attributes" I find poor

1. First Deuque should not return void it should be returning and integer(I'm not sure if I needed to change that for this assignment so I left it and worked around)
2. The classes and functions were on the same file as main loop
3. Could seperate the functions into a different file different then the class file or use template class
4. Did not deallocate the queue properly when calling the destructor
5. Could change variable such as front -> could be head and rear -> could be tail.


*/
#include <iostream>
#include <cstdlib>
#include "testQueue.h"
using namespace std;

// define default capacity of the queue
#define SIZE 10

// main function
int main()
{
    // call your test functions here!
    testQueueSize();
    testQueueisEmpty();
    testQueueisFull();
    testQueueDequeue();
    testQueueEnqueue();
    testQueuePeek();


    return 0;
}

