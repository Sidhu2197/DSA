#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

Node* rootinsert(Node* root,int val){
    if(root == NULL){
        root= new Node(val);
        return root;
    }

    if(val<root->data){//left subtree
        root->left=rootinsert(root->left,val);
    }
    else
    {
        root->right=rootinsert(root->right,val); // Fixed: was root->left
    }
    return root;
}

Node* buildbst(int arr[],int n){
    Node* root=NULL;

    for(int i=0;i<n;i++){
        root=rootinsert(root,arr[i]);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//to print values from one range to one range
void print(Node* root,int start,int end){
    if(root == NULL){
        return;
    }
    if(start<=root->data && root->data<=end){
        print(root->left,start,end);
        cout<<root->data<<" ";
        print(root->right,start,end);
    }
    else if(root->data<start)
    {
        print(root->right,start,end);
    }
    else
    {
        print(root->left,start,end);
    }
}

int main(){
    int arr[9]={8,5,3,1,4,6,10,11,14};

    Node* root=buildbst(arr,9);
    print(root,1,10);
    cout<<endl;
    return 0;
}