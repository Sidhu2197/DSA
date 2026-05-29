#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isvalid(string str){//0(n)
    stack<char> s;

    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];

        if(ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        else {
            if(s.empty()) {
                return false;
            }

            char top = s.top();
            if((top == '(' && ch == ')') ||
            (top == '[' && ch == ']') ||
            (top == '{' && ch == '}')) {
                s.pop();
            }
            else {
                return false;
            }
        }
    }

    return s.empty();
}

int main(){
    string str1 = "([}])";     // invalid: false
    string str2 = "([{}])";    // valid: true

    cout << isvalid(str1) << endl; // Output: 0
    cout << isvalid(str2) << endl; // Output: 1

    return 0;
}
