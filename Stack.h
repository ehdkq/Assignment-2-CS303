#include <vector>

using namespace std;

class Stack {
private:
    vector<int> stack_data;

public:
    void push(int value);
    void pop();
    int top() const;
    bool empty() const;
    double average() const;
};

