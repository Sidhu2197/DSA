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
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }

        temp->endofword = true;
    }

    bool search(string key) {
        Node* temp = root;

        for (int i = 0; i < key.size(); i++) {

            // Check whether current character exists as a child
            if (temp->children.count(key[i])) {

                // Move to the corresponding child node
                temp = temp->children[key[i]];
            }
            else {

                // Character not found, word doesn't exist
                return false;
            }
        }

        // Return true only if this node marks the end of a complete word
        return temp->endofword;
    }
};

int main() {
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;

    for (const string& word : words) {
        trie.insert(word);
    }

    cout << "the : "<< (trie.search("the") ? "Exists" : "Does Not Exist")<< endl;

    cout << "their : "<< (trie.search("their") ? "Exists" : "Does Not Exist")<< endl;

    cout << "th : "<< (trie.search("th") ? "Exists" : "Does Not Exist")<< endl;

    cout << "abc : "<< (trie.search("abc") ? "Exists" : "Does Not Exist")<< endl;

    return 0;
}

