// in this we will find kth level of a tree
// to find max distance from root to leaf

#include <iostream>
#include <vector>
using namespace std;

//code for sum of nodes

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;

// build tree from vector (-1 means NULL)
node* buildtree(vector<int> nodes) {
    idx++;
    if (nodes[idx] == -1) {
        return NULL;
    }

    node* currnode = new node(nodes[idx]);
    currnode->left = buildtree(nodes);
    currnode->right = buildtree(nodes);
    return currnode;
}

// sum of nodes in tree

int height(node* root){
    if(root==NULL){
        return 0;
    }

    int left_height=height(root->left);
    int right_height=height(root->right);

    int currheight= max(left_height,right_height)+1;
    return currheight;
}


int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int currdiameter= height(root->left)+height(root->right)+1;

    int left_diameter=diameter(root->left);
    int right_diameter=diameter(root->right);

    return max(currdiameter,max(left_diameter,right_diameter));
}

void kthhelper(node* root,int k,int currlevel){
    if(root == NULL){
        return;
    }

    if(currlevel == k){
        cout<<root->data<<" ";
        return;
    }
    kthhelper(root->left,k,currlevel+1);//left
    kthhelper(root->right,k,currlevel+1);//right
}

void kthlevel(node* root,int k){
    kthhelper(root,k,1);
}


int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    idx = -1; // reset index before building
    node* root = buildtree(nodes);
    kthlevel(root,2);
    return 0;
}
