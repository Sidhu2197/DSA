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

// height of nodes in tree

int height(node* root){
    if(root==NULL){
        return 0;
    }

    int left_height=height(root->left);
    int right_height=height(root->right);

    int currheight= max(left_height,right_height)+1;
    return currheight;
}


int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    idx = -1; // reset index before building
    node* root = buildtree(nodes);
    cout<<"height = "<<height(root)<<endl;
    return 0;
}
