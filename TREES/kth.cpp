//code for finding kth_ancestor ancestor of a tree
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

int kth_ancestor(node* root,int node,int k){
    if(root == NULL){
        return -1;
    }

    if(root->data == node){
        return 0;
    }

    int leftdis=kth_ancestor(root->left,node,k);
    int rightdis=kth_ancestor(root->right,node,k);

    if(leftdis ==-1 &&  rightdis==-1){
        return -1;
    }

    int validval=leftdis == -1 ? rightdis : leftdis;
    if(validval + 1 == k){
        cout<<"lth ancestor : "<<root->data;
    }

    return validval+1;
}



int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node *root=buildtree(nodes);

    int node=6,k=1;
    kth_ancestor(root,node,k);
    return 0;
}