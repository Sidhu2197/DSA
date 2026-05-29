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

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node *root=buildtree(nodes);
    cout<<"root ="<<root->data<<endl;
    return 0;
}