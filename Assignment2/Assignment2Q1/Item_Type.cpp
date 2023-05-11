struct Item_Type {
    // Each item has an integer value and a pointer to the next item
    int value;
    Item_Type* next;
};