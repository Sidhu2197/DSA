//implementation of linked list using queue

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class queue{  // <-- Fixed: removed parentheses here
    Node* head;
    Node* tail;
    
    public:
    queue(){
        head=tail=NULL;
    }

    void push(int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
    }

    void pop(){
        if(empty()){
            cout<<"queue is empty\n";
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    int front(){
        if(empty()){
            cout<<"queue is empty\n";
            return -1;
        }
        return head->data;
    }

    bool empty(){
        return head==NULL;
    }
};

int main(){
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    while(!q.empty()){
    cout<<q.front()<<endl; // 10
    q.pop();
}
return 0;
}
