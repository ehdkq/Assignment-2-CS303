#include "SingleLinkedList.h"
#include <stdexcept>

using namespace std;

template<typename Item_Type>
//creates a linked list with a nullptr head and tail
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

template<typename Item_Type>
//if the linked list is not empty, it gets rid of the first element
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) {
        pop_front();
    }
}

template<typename Item_Type>
//it adds a new item to the front of the list
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* new_node = new Node(item, head);
    head = new_node;
    if (num_items == 0) {
        tail = head;
    }
    num_items++;
}

//adds a new item to the end of the list
template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item);
    //if it's not empty, the current tail goes to the new node
    if (tail) {
        tail->next = new_node;
        tail = new_node;
    }
    //if it's empty, set both head and tail to the new node
    else {
        head = tail = new_node;
    }
    num_items++;
}

//removes the first item from the list
template<typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    //throws an error if it's out of range
    if (empty()) throw out_of_range("List is empty");
    Node* old_head = head;
    head = head->next;
    delete old_head;
    num_items--;
    //if the list is empty, set the tail to null
    if (num_items == 0) {
        tail = nullptr;
    }
}


//removes the last item from the list
template<typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) throw out_of_range("List is empty");
    if (num_items == 1) {
        pop_front();
        return;
    }
    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
    num_items--;
}

//returns the first item in the list
template<typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (empty()) throw out_of_range("List is empty");
    return head->data;
}

//returns the last item in the list
template<typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    if (empty()) throw out_of_range("List is empty");
    return tail->data;
}

//checks if empty
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return num_items == 0;
}

//inserts an item at a certain index
template<typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index >= num_items) {
        push_back(item);
    }
    else if (index == 0) {
        push_front(item);
    }
    else {
        Node* current = head;
        for (size_t i = 1; i < index; ++i) {
            current = current->next;
        }
        Node* new_node = new Node(item, current->next);
        current->next = new_node;
        num_items++;
    }
}

//removes an item at specific index
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) return false;
    if (index == 0) {
        pop_front();
        return true;
    }
    //goes to the node before the one to remove
    Node* current = head;
    for (size_t i = 1; i < index; ++i) {
        current = current->next;
    }
    Node* to_remove = current->next; //node to remove
    current->next = to_remove->next;//bypass the node
    if (to_remove == tail) {
        tail = current; //update tail if last node is gone
    }
    delete to_remove; //free memory
    num_items--;
    return true;
}

//finds first occurance of an item and returns its index
template<typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;
}
