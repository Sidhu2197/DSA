#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
    string key;
    int value;
    Node* next;

    Node(string key,int val){
        this->key=key;
        this->value=val;
        next=NULL;
    }
};

class HashTable{
    int totalsize;
    Node** table;

    int hashfunction(string key){
        int idx=0;
        for(int i=0;i<key.size();i++){
            idx = idx + (key[i]*key[i]) % totalsize;
        }
        return idx % totalsize;
    }

    public:
    HashTable(int size=5){
        totalsize=size;
        table = new Node*[totalsize];
        for(int i=0;i<totalsize;i++){
            table[i]=NULL;
        }
    }

    void insert(string key,int val){
        int idx=hashfunction(key);
        
        Node* newNode = new Node(key,val);
        newNode->next=table[idx];
        table[idx]=newNode;
    }

    int search(string key){
        int idx=hashfunction(key);
        Node* temp=table[idx];
        while(temp!=NULL){
            if(temp->key == key){
                return temp->value;
            }
            temp=temp->next;
        }
        return -1;
    }
};

int main(){
    HashTable ht;

    ht.insert("india",150);
    ht.insert("china",150);
    ht.insert("us",50);

    cout<<"india population : "<<ht.search("india")<<endl;
    cout<<"nepal population : "<<ht.search("nepal")<<endl;

    return 0;
}
