#include <iostream>
#include "Stack.h"

using namespace std;

int main() {

    //creates stack
    Stack s;

    //check if stack is empty
    cout << "Stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    //push elements to stack
    s.push(10);
    s.push(20);
    s.push(30);

    //display top element
    cout << "Top element: " << s.top() << endl;

    //remove top element
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;

    //display average of stack
    cout << "Average value: " << s.average() << endl;

    return 0;
}
