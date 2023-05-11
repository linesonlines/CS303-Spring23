#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue q = Queue();

    q.enter_queue(06);
    cout << "Insert occurred:" << endl;
    q.print();
    q.enter_queue(12);
    cout << "Insert occurred:" << endl;
    q.print();
    q.enter_queue(97);
    cout << "Insert occurred:" << endl;
    q.print();

    cout << "Front element: " << q.look_at_front() << endl;
    cout << "Total elements in queue: " << q.num_elements() << endl;

    q.next();
    cout << "Removal occurred:" << endl;
    q.print();
    q.next();
    cout << "Removal occurred:" << endl;
    q.print();

    cout << "Front element: " << q.look_at_front() << endl;
    cout << "Total elements in queue: " << q.num_elements() << endl;

    q.next();
    cout << "Removal occurred:" << endl;
    q.print();

    if (q.isEmpty()) {
        cout << "The queue is empty." << endl;
    } else {
        cout << "The queue is NOT empty." << endl;
    }

    return 0;
}