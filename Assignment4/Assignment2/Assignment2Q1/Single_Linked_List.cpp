#include <iostream>
#include <string>
#include "Item_Type.h"
#include "Single_Linked_List.h"
using namespace std;

    // Constructor for Single Linked List
    // The head and tail are pointers
    // Num_items is number of items in list
    Single_Linked_List::Single_Linked_List() {
        head = nullptr;
        tail = nullptr;
        num_items = 0;
    }

    // Pushes an item with new value into head
    void Single_Linked_List::push_front(int val) {
        
        // Each item has an integer value and a pointer to the next item
        // Construct a new item with parameter value
        Item_Type* new_item = new Item_Type;
        new_item->value = val;
        new_item->next = head;

        // Make the new item the head
        head = new_item;

        // If list has only one item, tail is also new item
        if (tail == nullptr) {
            tail = new_item;
        }

        // Increment number of items
        num_items++;

        // For output purposes
        cout << "Item pushed to front" << endl;
        print_list();
    }
    
    // Pushes an item with new value into tail
    void Single_Linked_List::push_back(int val) {

        // Each item has an integer value and a pointer to the next item
        // Construct a new item with parameter value
        Item_Type* new_item = new Item_Type;
        new_item->value = val;
        new_item->next = nullptr;

        // If list is empty, head and tail are new item
        if(head == nullptr) {
            head = new_item;
            tail = new_item;
        }
        else {
            // Otherwise the tail needs to point to the new item
            // New item becomes tail
            tail->next = new_item;
            tail = new_item;
        }

        // Increment number of items
        num_items++;

        // For output purposes
        cout << "Item pushed to back" << endl;
        print_list();
    }

    // Removes first item in list and returns its value
    int Single_Linked_List::pop_front() {
        // If list is empty return -1
        if(num_items == 0) {
            return -1;
        }

        // Store the head's value to return
        int val = head->value; 
        // Head's next item becomes the head
        head = head->next;

        // If head is now null, then so is the tail
        if(head == nullptr) {
            tail = nullptr;
        }

        // Decrement number of items
        num_items--;

        // For output purposes
        cout << "Item removed from front" << endl;
        print_list();
        return val;
    }

    // Removes last item in list and returns its value
    int Single_Linked_List::pop_back() {
        // If list is empty return -1
        if (num_items == 0) {
            return -1;
        }
        int value;

        // If only one item in list, then head's value is returned
        // and head and tail are both null
        if (num_items == 1) {
            value = head->value;
            head = nullptr;
            tail = nullptr;
            num_items--;
        } else {
            //Otherwise, iterate through the list until the one before tail is found
            Item_Type* new_tail = head;
            while (new_tail->next != tail) {
                new_tail = new_tail->next;
            }
            // Store tail's value to return
            value = tail->value;
            // Make old tail the new tail
            tail = new_tail;
            // Make tail's next null
            tail->next = nullptr;
            // Decrement number of items
            num_items--;
        }

        // For output purposes
        cout << "Item removed from back" << endl;
        print_list();
        return value;
    }

    // Return's head's value
    int Single_Linked_List::front() {
        return (*head).value;
    }

    // Return's tail's value
    int Single_Linked_List::back() {
        return (*tail).value;
    }

    // Removes all items from the linked list
    void Single_Linked_List::empty() {
        // Iterates through the list starting with head
        // Shifting everything up until the head becomes null
        while (head != nullptr) {
            Item_Type* temp = head;
            head = head->next;
        }
        // Makes tail null
        tail = nullptr;
        // Sets number of items to zero
        num_items = 0;

        // For output purposes
        cout << "List emptied" << endl;
        print_list();
    }

    // Inserts an item at a given index
    void Single_Linked_List::insert(size_t index, const Item_Type& item) {
        if(index >= num_items || index < 0) {
            // Inserts to end of list if the index is out of range using push_back() method
            push_back(item.value);
        }

        // If index is 0, it's the same as push_front()
        if(index == 0) {
            push_front(item.value);
        } else {
            // Otherwise, create a new item with the parameter's value and a null next
            Item_Type* new_item = new Item_Type;
            new_item->value = item.value;
            new_item->next = nullptr;
            // Start at the head and move to the next until you reach the desired index - 1
            Item_Type* current = head;
            for(size_t i = 0; i < index - 1; i++) {
                current = current->next;
            }
            // Make the new item's next where you left off in for loop
            new_item->next = current->next;
            // Make the current item's next the next_item
            current->next = new_item;
            // If the new item's next is null, then it is the tail
            if(new_item->next == nullptr) {
                tail = new_item;
            }
            // Increment number of items
            num_items++;
        }

        // For output purposes
        print_list();
    }

    // Removes item from list
    bool Single_Linked_List::remove(size_t index) {
        // If index out of bounds, return false
        if(index >= num_items || index < 0) {
            cout << "Cannot remove, index out of bounds" << endl;
            print_list();
            return false;
        }

        // If index is head, then pop_front() is the same thing
        if(index == 0) {
            pop_front();
        }
        else {
            // Otherwise, start at the head and iterate until the desired index - 1
            Item_Type* current = head;
            for(size_t i = 0; i < index - 1; i++) {
                current = current->next;
            }
            // Remove the item after where you left off in the for loop
            Item_Type* item_to_remove = current->next;
            current->next = item_to_remove->next;

            //Decrement number of items
            num_items--;

            //Reassign tail if necessary
            if(current->next == nullptr) {
                tail = current;
            }
        }

        // For output purposes
        cout << "Item removed from index: " << index << endl;
        print_list();
        return true;
}

    // Return the position of the first occurrence of value if it is found. 
    // Returns the size of the list if it is not found. 
    size_t Single_Linked_List::find(const Item_Type& item) {
        Item_Type* current = head;
        size_t index = 0;
        while (current != nullptr) {
            // Iterate through the list starting at head
            // Check if item's value matches
            if (current->value == item.value) {
                // Return index if found
                return index;
            }
            current = current->next;
            index++;
        }
        // Not found, returns number of items
        cout << "Item not found, returning size of list" << endl;
        return num_items;
    }

    // For output purposes
    // Prints the list in brackets separated by commas
    void Single_Linked_List::print_list() {
        Item_Type* current = head;
        cout << "[";
        // Starts at head and iterates to the next, printing along the way
        while(current != nullptr) {
            cout << current->value << ", ";
            current = current->next;
        }
        cout << "]";
        cout << endl;
    }