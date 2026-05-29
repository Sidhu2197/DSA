#include <iostream>
#include <vector>
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

Node* buildBSTfromvector(vector<int> arr, int si, int ei) {
    if (si > ei) {
        return NULL;
    }
    int mid = si + (ei - si) / 2;
    Node* root = new Node(arr[mid]);

    root->left = buildBSTfromvector(arr, si, mid - 1);
    root->right = buildBSTfromvector(arr, mid + 1, ei);

    return root;
}

void preorder(Node* root) {
    if (root == NULL)
        return;
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}

void getpreorder(Node* root, vector<int>& arr) {
    if (root == NULL){
        return;
    }
    arr.push_back(root->data);
    getpreorder(root->left, arr);
    getpreorder(root->right, arr);
}

Node* balancedBST(Node* root) {
    vector<int> arr;
    getpreorder(root, arr);
    return buildBSTfromvector(arr, 0, arr.size() - 1);
}

int main() {
    Node* root = new Node(6);

    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    preorder(root);
    cout << endl;

    root = balancedBST(root);

    preorder(root);
    cout << endl;

    return 0;
}
