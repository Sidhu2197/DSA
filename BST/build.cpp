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
        root = new Node(val);
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

int main(){
    int arr[6]={5,1,3,4,2,7};

    Node* root=buildbst(arr,6);
    inorder(root);
    cout<<endl;
    return 0;
}