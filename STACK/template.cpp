#include <bits/stdc++.h>
#include<string>
using namespace std;

// Creating a generic Stack class using vector
template <class T>
class Stack {
    vector<T> vec;
public:
    void push(T val) { // O(1)
        vec.push_back(val);
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        vec.pop_back();
    }

    T top() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return T(); // Return default value
        }
        return vec.back(); // cleaner than manual index
    }

    bool isEmpty() {
        return vec.empty(); // same as size() == 0
    }
};

int main() {
    Stack<string> s; // use your custom Stack class, not STL stack
    s.push("cars");
    s.push("are");
    s.push("cats");

    while (!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
