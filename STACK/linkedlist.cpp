// push(val)=>;;.pushfront()
// pop()=>ll.popfront()
// top=>ll.head->data
//implemenatation of stack using linked list

#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

//creating stack using linked list
template<class T>
class Stack{
    list<T> LL;

    public:

    void push(T val){
        LL.push_front(val);
    }

    void pop(){
        LL.pop_front();
    }

    T top(){
        return LL.front();
    }

    bool isEmpty(){
        return LL.size()==0;
    }


};


int main() {
    Stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;

}