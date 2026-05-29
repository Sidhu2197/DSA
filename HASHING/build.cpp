#include<iostream>
#include<vector>
#include<string>
using namespace std;

//node represents linked list
class Node{
    public:
    string key;
    int value;
    Node* next;

    Node(string key,int val){
        this->key=key;
        this->value=value;
        next=NULL;
    }
};

class HashTable{
    int totalsize;
    int currsize;
    Node** table;

    public:
    HashTable(int size=5){
        totalsize=size;
        currsize=0;

        table = new Node*[totalsize];

        for(int i=0;i<totalsize;i++){
            table[i]=NULL;
        }
    }
};

int main(){
    HashTable ht;

    return 0;
}


//hash table functions are insert,erase,search