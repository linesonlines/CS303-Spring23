#include <iostream>
#include "Queue.h"

using namespace std;

// Constructs a queue with a max of 100
// Initialize rear to -1
// Initialize num_items to 0
Queue::Queue() {
    this->max = 100;
    this->rear = -1;
    this->num_items = 0;
    arr = new int[max];
}

// Inserts item into queue
void Queue::enter_queue(int item) {
    // Checks if queue is full
    if (rear == max - 1) {
        cout << "Cannot accept any more items in this queue." << endl;
        return;
    }

    // Move rear
    rear++;
    //Put new item in rear
    arr[rear] = item;
    // Increment number of items
    num_items++;
}

// Retrieves next in queue
int Queue::next() {
    // Checks if queue is empty
    if (num_items == 0) {
        cout << "The queue is empty." << endl;
        return -1;
    }

    // Stores front of queue for returning
    int item = arr[0];
    //Shift items down
    for (int i = 0; i < rear; i++){
        arr[i] = arr[i+1];
    }
    
    // Move rear
    rear--;
    // Decrement number of items
    num_items--;
    // Return front from earlier
    return item;
}

// Returns front of queue without removing
int Queue::look_at_front() {
    // Checks if queue is empty
    if (num_items == 0) {
        cout << "The queue is empty." << endl;
        return -1;
    }
    // Returns front of queue
    return arr[0];
}

// Returns true if empty, false otherwise
bool Queue::isEmpty() {
    return (num_items == 0);
}

// Returns number of elements
int Queue::num_elements() {
    return num_items;
}

// Prints queue
void Queue::print() {
    cout << "[";
    if (isEmpty()) {
        cout << " ";
    }
    else {
        for (int i = 0; i <= rear; i++) {
            cout << arr[i] << ", ";
        }
    }
    cout << "]" << endl;
}
