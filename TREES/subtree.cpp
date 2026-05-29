// subtree means return true if there is a subtree of root with the same structure and node values of subroot and false otherwise


#include <iostream>
#include <vector>
using namespace std;

//code for construction of class

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
//we will analyze whole tree here
bool isidentical(node *root1,node *root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    else if(root1 == NULL || root2 == NULL){
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

    return isidentical(root1->left,root2->left)&&
    isidentical(root1->right,root2->right);

}

bool issubtree(node *root,node *subroot){
    if(root == NULL && subroot == NULL){
        return true;
    }
    else if(root == NULL || subroot == NULL){
        return false;
    }

    if(root->data==subroot->data){
        //checking if it is identical for sub trees
        int isleftsubtree=issubtree(root->left,subroot);
        
        if(!isleftsubtree){
        issubtree(root->right,subroot);
        }
    }

}

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root = buildtree(nodes);
    
    node* subroot=new node(2);
    subroot->left=new node(4);
    subroot->right=new node(5);

    cout<<issubtree(root,subroot)<<endl;
    return 0;
}
