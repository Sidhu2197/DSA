#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Stack {
    vector<int> stack;

public:
    void push(int val) {
        stack.push_back(val);
    }

    void pop() {
        if (isEmpty()) {
            cout << "STACK IS EMPTY" << endl;
            return;
        }
        stack.pop_back();
    }

    int top() {
        if (isEmpty()) {
            cout << "STACK IS EMPTY" << endl;
            return -1;
        }
        int lidx = stack.size() - 1;
        return stack[lidx];
    }

    bool isEmpty() {
        return stack.size() == 0;
    }
};

int main() {
    Stack meow;   // FIXED: Correct object creation
    meow.push(3);

    cout << "Top element: " << meow.top() << endl;
    meow.pop();
    meow.pop(); // To test popping from an empty stack
    return 0;
}
