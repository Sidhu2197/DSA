#include<iostream>
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

// Insert into BST
node* insert(node* root, int data) {
    if (root == NULL) return new node(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

// Inorder Traversal (to see tree in sorted order)
void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Helper: Find inorder successor (smallest in right subtree)
node* inorderSuccessor(node* root) {
    while (root && root->left != NULL) root = root->left;
    return root;
}

// Delete node in BST
node* delNode(node* root, int val) {
    if (root == NULL) return NULL;

    if (val < root->data) {
        root->left = delNode(root->left, val);
    }
    else if (val > root->data) {
        root->right = delNode(root->right, val);
    }
    else
    {
        // Case 1: No children
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        node* succ = inorderSuccessor(root->right);
        root->data = succ->data; // replace with inorder successor
        root->right = delNode(root->right, succ->data);
    }
    return root;
}

int main() {
    node* root = NULL;
    int arr[] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Build BST
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    inorder(root);
    cout << endl;

    // Delete node 4
    root = delNode(root, 4);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
