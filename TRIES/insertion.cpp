#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    unordered_map<char, Node*> children;
    bool endofword;

    Node() {
        endofword = false;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string key) {
        Node* temp = root;

        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i]) == 0) {
                // INSERT happens here — new node created for this character
                temp->children[key[i]] = new Node();
            }
            // Move to the next node (existing or newly created)
            temp = temp->children[key[i]];
        }
        // Mark end of word — signals a complete word ends at this node
        temp->endofword = true;
    }
};

int main() {
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;

    for (const string& word : words) {
        trie.insert(word);
    }

    return 0;
}