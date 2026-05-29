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

// Inorder traversal (store in vector)
void inorder(Node* root, vector<int>& arr) {
    if (root == NULL) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// Merge two sorted arrays
vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) merged.push_back(a[i++]);
        else merged.push_back(b[j++]);
    }
    while (i < a.size()) merged.push_back(a[i++]);
    while (j < b.size()) merged.push_back(b[j++]);
    return merged;
}

// Build Balanced BST from sorted array
Node* buildBSTfromArray(vector<int>& arr, int si, int ei) {
    if (si > ei)
    return NULL;
    int mid = si + (ei - si) / 2;
    Node* root = new Node(arr[mid]);
    root->left = buildBSTfromArray(arr, si, mid - 1);
    root->right = buildBSTfromArray(arr, mid + 1, ei);
    return root;
}

// Merge two BSTs
Node* mergeBST(Node* root1, Node* root2) {
    vector<int> nodes1, nodes2;
    inorder(root1, nodes1);
    inorder(root2, nodes2);

    vector<int> merged = mergeArrays(nodes1, nodes2);

    Node* finalRoot = buildBSTfromArray(merged, 0, merged.size() - 1);
    return finalRoot;
}

// Print preorder of final merged BST
void preorderPrint(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main() {
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node* mergedRoot = mergeBST(root1, root2);

    preorderPrint(mergedRoot);
    cout << endl;

    return 0;
}
