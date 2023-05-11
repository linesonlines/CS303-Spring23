#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    int num_items, rear, max;
    int *arr;
public:
    Queue();
    void enter_queue(int item);
    int next();
    int look_at_front();
    bool isEmpty();
    int num_elements();
    void print();
};

#endif
