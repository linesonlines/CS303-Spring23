#include "Item_Type.h"
#include "Single_Linked_List.h"
#include <iostream>
using namespace std;

int main() {
    Single_Linked_List my_list;

    // push items onto the front of the list
    my_list.push_front(1);
    my_list.push_front(6);
    my_list.push_front(0);

    // push items onto the back of the list
    my_list.push_back(2);
    my_list.push_back(9);
    my_list.push_back(7);

    // print the front and back items
    cout << "Front item: " << my_list.front() << endl;
    cout << "Back item: " << my_list.back() << endl;

    // remove items from the front and back of the list
    my_list.pop_front();
    my_list.pop_back();

    // insert an item into the list
    int value2 = 7;
    int index = 2;
    Item_Type item_to_insert = {value2, nullptr};
    my_list.insert(index, item_to_insert);
    cout << "Item with value " << value2 << " was inserted at index " << index << endl;

    // remove an item from the list
    my_list.remove(3);

    int value = 7;
    Item_Type item_to_find = {value, nullptr};
    // print the position of an item in the list
    cout << "Index of item with value " << value << ": " << my_list.find(item_to_find) << endl;

    // empty the list
    my_list.empty();

    return 0;
}
