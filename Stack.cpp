#include "Stack.h"
#include <stdexcept>
#include <numeric>

using namespace std;

//pushes value onto stack
void Stack::push(int value) {
    stack_data.push_back(value);
}
//removes first value from stack
void Stack::pop() {
    if (stack_data.empty()) throw out_of_range("Stack is empty");
    stack_data.pop_back();
}
//returns value at top of stack
int Stack::top() const {
    if (stack_data.empty()) throw out_of_range("Stack is empty");
    return stack_data.back();
}
// returns true if stack is empty
bool Stack::empty() const {
    return stack_data.empty();
}
//gives average value of all the values in the stack
double Stack::average() const {
    if (stack_data.empty()) return 0.0;
    int sum = accumulate(stack_data.begin(), stack_data.end(), 0);
    return static_cast<double>(sum) / stack_data.size();
}
