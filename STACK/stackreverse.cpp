#include<iostream>
#include<stack>
#include<string>
using namespace std;

// push at bottom
void bottom(stack<int>& s, int val) { // O(n)
    if (s.empty()) {
        s.push(val); // push at top = push at bottom if empty
        return;
    }
    int temp = s.top();
    s.pop();
    bottom(s, val);
    s.push(temp);
}

// reverse a string using stack
string reverse(string str) { // TC:SC = O(n):O(n)
    string ans;
    stack<char> s;

    for (int i = 0; i < str.size(); i++) {
        s.push(str[i]);
    }

    while (!s.empty()) {
        char top = s.top();
        ans += top;
        s.pop();
    }
    return ans;
}

// reverse a stack using recursion
void reverse(stack<int>& s) {
    if (s.empty())
    return;
    int temp = s.top();
    s.pop();
    reverse(s);
    bottom(s, temp);
}

void printstack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    cout<<"\n";

};

int main() {

    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    printstack(s);
    reverse(s);
    printstack(s);

    return 0;
}
