
#include "testQueue.h"
#include "queue.h"

/* Test ID: size queue check - EQC
Unit: queue::size ()
Description: test to determine if queue::size () enqueues numbers and shows the correct size of the queue
Test steps:
1. enqueue data
2. call size() to see if its equal to the amount added
3. Conditionally evaluate the value returned by queue::size ()
Test data: size = 2
Precondition: queue is empty
Postcondition: queue has a size of 2
Expected result: queue is empty; pass is returned
Actual result: queue is empty; pass is returned
Status: passed
*/
void testQueueSize() {
    queue q(5);
    q.enqueue(10);
    q.enqueue(20);

    if (q.size() == 2) {
        std::cout << "testQueueSize: PASS\n";
    } else {
        std::cout << "testQueueSize: FAIL\n";
    }
}

/* Test ID: Empty queue check - EQC
Unit: queue::isEmpty ()
Description: test to determine if queue::isEmpty () returns 1 if a queue object
is empty.
Test steps:
1. Construct an empty queue object
2. Invoke queue::isEmpty ()
3. Conditionally evaluate the value returned by queue::isEmpty ()
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object is still empty
Expected result: queue is empty; pass is returned
Actual result: queue is empty; pass is returned
Status: passed
*/
void testQueueisEmpty() {
    queue q(5);

    if (q.isEmpty()) {
        std::cout << "testQueueisEmpty: PASS\n";
    } else {
        std::cout << "testQueueisEmpty: FAIL\n";
    }
}

/* Test ID: Isfull queue check - EQC
Unit: queue::isFull ()
Description: test to determine if queue::isFull () returns pass if a queue object
is full.
Test steps:
1. Construct an empty queue object and enqueue() 
2. then check if queue is full using if statements
3. Conditionally evaluate the value returned by queue::isFull()
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object is full
Expected result: queue is full; Pass is returned
Actual result: queue is empty; Pass is returned
Status: passed
*/
void testQueueisFull() {
    queue q(2);
    q.enqueue(10);
    q.enqueue(20);

    if (q.isFull()) {
        std::cout << "testQueueisFull: PASS\n";
    } else {
        std::cout << "testQueueisFull: FAIL\n";
    }
}

/* Test ID: Dequeue queue check - EQC
Unit: queue::isEmpty ()
Description: test to determine if queue::Dequeue () returns pass if a queue object
is properly dequeued.
Test steps:
1. Construct an empty queue object
2. Invoke queue::enqueue ()
3. Conditionally evaluate the value returned by queue::dequeue ()
Test data: size = 0
Precondition: object is enqueued
Postcondition: queue object is  empty and dequeued
Expected result: queue is dequeued; pass is returned
Actual result: queue is dequeueed; pass is returned
Status: passed but failed underflow
*/
void testQueueDequeue() {
   queue q(5);  

    q.enqueue(10);
    q.enqueue(20);

    q.dequeue();  
    if (q.size() == 1) {
        std::cout << "testQueueDequeue: PASS\n";
    } else {
        std::cout << "testQueueDequeue: FAIL\n";
    }

    q.dequeue();  
    if (q.isEmpty()) {
        std::cout << "testQueueDequeue (empty): PASS\n";
    } else {
        std::cout << "testQueueDequeue (empty): FAIL\n";
    }
    q.dequeue();  
    if (q.isEmpty()) {  
        std::cout << "testQueueUnderflow: PASS\n";
    } else {
        std::cout << "testQueueUnderflow: FAIL\n";
    }
}

/* Test ID: Enqueue queue check - EQC
Unit: queue::enqueue ()
Description: test to determine if queue::enwuwue () returns pass if a queue object
is enqueued.
Test steps:
1. Construct an empty queue object 
2. Invoke queue::enqueue ()
3. Conditionally evaluate the value returned by queue::enqueue ()
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object is enqueued empty
Expected result: queue is not empty; pass is returned
Actual result: queue is not empty; 1 is returned
Status: passed
*/
void testQueueEnqueue() {
    queue q(5);
    q.enqueue(10);
    q.enqueue(20);

    if (q.size() == 2) {
        std::cout << "testQueueEnqueue: PASS\n";
    } else {
        std::cout << "testQueueEnqueue: FAIL\n";
    }
}

/* Test ID: Peek queue check - EQC
Unit: queue::peek ()
Description: test to determine if queue::peek () returns pass if a queue object
is enqueued and returns correct value.
Test steps:
1. Construct an empty queue object
2. Invoke queue::enqueue ()
3. Conditionally evaluate the value returned by queue::peek ()
Test data: size = 0
Precondition: queue object is empty
Postcondition: queue object is not empty
Expected result: peek is 10; pass is returned
Actual result: peek is 10; pass is returned
Status: passed
*/
void testQueuePeek() {
    queue q(5);
    q.enqueue(10);

    if (q.peek() == 10 && q.size() == 1) {
        std::cout << "testQueuePeek: PASS\n";
    } else {
        std::cout << "testQueuePeek: FAIL\n";
    }
}

