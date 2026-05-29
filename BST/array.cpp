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

Node* buildBST(int arr[], int si, int ei) {
    if (si > ei) {
        return NULL;
    }
    int mid = si + (ei - si) / 2;
    Node* root = new Node(arr[mid]);

    root->left = buildBST(arr, si, mid - 1);
    root->right = buildBST(arr, mid + 1, ei);

    return root;
}

void preorder(Node* root) {
    if (root == NULL)
    return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int arr[] = {3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = buildBST(arr, 0, n - 1);
    preorder(root);
    cout << endl;

    return 0;
}
