#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iostream>
#include "Item_Type.h"

class Single_Linked_List {
private:
    Item_Type* head;
    Item_Type* tail;
    size_t num_items;
public:
    Single_Linked_List();
    void push_front(int val);
    void push_back(int val);
    int pop_front();
    int pop_back();
    void empty();
    int front();
    int back();
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item);
    void print_list();
};

#endif /* SINGLE_LINKED_LIST_H */