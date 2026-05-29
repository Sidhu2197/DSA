#include <iostream>
#include <vector>
using namespace std;

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

// preorder traversal
void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// transform tree into sum tree
int transform(node* root) {
    if (root == NULL) {
        return 0;
    }

    // recursively get old values of left and right subtrees
    int leftold = transform(root->left);
    int rightold = transform(root->right);

    int currold = root->data; // store original data

    // set current node's data = sum of left and right subtree values
    root->data = leftold + rightold;

    // return total sum including original value of this node
    return currold + root->data;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    node* root = buildtree(nodes);

    transform(root);

    cout << "Preorder after transform: ";
    preorder(root);
    cout << endl;

    return 0;
}
