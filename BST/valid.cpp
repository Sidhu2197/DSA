// here we will check whether a tree is a vslid bst or not //in valid bst we should check that left 
// left subtree<node
// right subtree>node
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Insert value into BST
Node* rootInsert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = rootInsert(root->left, val);
    else
        root->right = rootInsert(root->right, val);
    return root;
}

// Validate BST
bool validateHelper(Node* root, Node* minNode, Node* maxNode) {
    if (!root) return true;
    if ((minNode && root->data <= minNode->data) || 
        (maxNode && root->data >= maxNode->data))
        return false;
    return validateHelper(root->left, minNode, root) &&
        validateHelper(root->right, root, maxNode);
}

bool isValidBST(Node* root) {
    return validateHelper(root, NULL, NULL);
}

int main() {
    int arr[6] = {5, 1, 3, 4, 2, 7};
    Node* root = NULL;

    for (int i = 0; i < 6; i++)
        root = rootInsert(root, arr[i]);

    cout << (isValidBST(root) ? "Yes" : "No") << endl;
    return 0;
}
