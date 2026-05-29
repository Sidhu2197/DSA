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

int sum(node* root){
    if(root==NULL){
        return 0;
    }

    int leftsum=sum(root->left);
    int rightsum=sum(root->right);

    int currsum= leftsum+rightsum+root->data;
    cout<<"sum = "<<currsum<<endl;
    return currsum;
}


int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    idx = -1; // reset index before building
    node* root = buildtree(nodes);

    cout<<"sum of nodes : "<<sum(root)<<endl;
    return 0;
}
