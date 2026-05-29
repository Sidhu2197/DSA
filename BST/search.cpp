// binary search tree
#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int data){
        this->data=data;
        left=right=NULL;
    }
};

static int idx=-1;

node* buildtree(vector<int>nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    
    node* currnode= new node(nodes[idx]);//1
    currnode->left = buildtree(nodes);//2
    currnode->right = buildtree(nodes);//3
    return currnode;
}

// Insert function for BST
node* insert(node* root, int data) {
    if (root == NULL) {
        return new node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to build BST from array
node* buildbst(int arr[], int size) {
    node* root = NULL;
    for (int i = 0; i < size; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    //left
    inorder(root->left);
    // root
    cout<<root->data<<" ";
    // right
    inorder(root->right);
}

bool search(node* root,int key){
    if(root == NULL){
        return false;
    }
    
    if(root->data == key){//found
        return true;
    }
    if(root->data > key){//left subtree
        return search(root->left,key);
    }
    else{
        return search(root->right,key);//right subtree
    }
}

int main(){
    int arr[9]={8,5,3,1,4,6,10,11,14};
    node* root=buildbst(arr,9);
    
    int key;
    cin>>key;
    if(search(root,key)){
        cout<<key<<" is present in the tree"<<endl;
    }
    else{
        cout<<key<<" is not present in the tree"<<endl;
    }
    
    return 0;
}