#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void bottom(stack<int>&s,int val){// 0(n)

    if(s.empty()){
        s.push(val);//push at top = push at bottom
        return;
    }
    int temp=s.top();
    s.pop();
    bottom(s,val);
    s.push(temp);

};

int main(){
    stack<int>s;

    s.push(3);
    s.push(2);
    s.push(1);

    bottom(s,4);


    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    cout<<endl;

    return 0;
}