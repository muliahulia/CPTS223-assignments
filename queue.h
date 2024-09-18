#include <iostream>
#include <cstdlib>
using namespace std;

// define default capacity of the queue
#define SIZE 10

// Class for queue
class queue //changed to capital (dont know if that changes anything)
{
    int* arr;		// array to store queue elements
    int capacity;	// maximum capacity of the queue
    int front;		// front points to front element in the queue (if any)
    int rear;		// rear points to last element in the queue
    int count;		// current size of the queue

public:
    queue(int size = SIZE); 	// constructor
    ~queue();   				// destructor

    void dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};  // Missing semi collon 

// Constructor to initialize queue
queue::queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor to free memory allocated to the queue
queue::~queue()
{
    delete[] arr;  // changed delere arr to delete[] arr to prop deallocate it
    
    // you are not required to test this function;
    // however, are there issues with it? 
}

// Utility function to remove front element from the queue
void queue::dequeue() {
    // check for queue underflow
    if (isEmpty()) {
        std::cerr << "UnderFlow\nProgram Terminated\n";
    }

    //  int element = arr[front];  // added element
    std::cout << "Removing " << '\n'; // double arrow

    front = (front + 1) % capacity;
    count--;

   //  return element;  // return the removed element
}


// Utility function to add an item to the queue
void queue::enqueue(int item)
{
    // check for queue overflow
    if (isFull())  // spelling error
    {
        cout << "OverFlow\nProgram Terminated\n";
        return;
    }

    cout << "Inserting " << item << '\n';

    rear = (rear + 1) % capacity;
    arr[rear] = item; // equals item not size
    count++;
}

// Utility function to return front element in the queue
int queue::peek()
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        return numeric_limits<int>::min();
    }
    return arr[front]; // need to return front not rear for peek
}

// Utility function to return the size of the queue
int queue::size()
{
    return count ;// not +1
}

// Utility function to check if the queue is empty or not
bool queue::isEmpty()
{
    return (size() == 0);
}

// Utility function to check if the queue is full or not
bool queue::isFull()
{
    return (size()-1 == capacity); // needs double equal
}
