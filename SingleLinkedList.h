#include <cstddef> // for size_t

using namespace std;

//template class for the single linked list
template<typename Item_Type>
class Single_Linked_List {
private:
    struct Node {
        //the node represents a single element in the linked list
        Item_Type data;
        Node* next;
        //constructor to initalize node with data and a pointer
        Node(const Item_Type& item, Node* next_ptr = nullptr)
            : data(item), next(next_ptr) {}
    };
    Node* head;
    Node* tail;
    size_t num_items;

public:

    //constructor to initalize an empty list and the matching destructor to clean up the list
    Single_Linked_List();
    ~Single_Linked_List();

    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    Item_Type front() const;
    Item_Type back() const;
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item) const;
};


