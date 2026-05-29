#include<iostream>
#include<string>
using namespace std;

// Node represents linked list
class Node {
public:
    string key;
    int value;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->value = val;
        next = NULL;
    }

    ~Node() {
        if (next != NULL) {
            delete next;   // delete rest of linked list
        }
    }
};

class HashTable {
    int totalsize;
    int currsize;
    Node** table;

    int hashfunction(string key) {
        int idx = 0;
        for (int i = 0; i < key.size(); i++) {
            idx = idx + (key[i] * key[i]) % totalsize;
        }
        return idx % totalsize;
    }

public:
    HashTable(int size = 5) {
        totalsize = size;
        currsize = 0;
        table = new Node*[totalsize];
        for (int i = 0; i < totalsize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int val) {
        int idx = hashfunction(key);
        Node* newNode = new Node(key, val);
        newNode->next = table[idx];
        table[idx] = newNode;
        currsize++;
    }

    void printTable() {
        for (int i = 0; i < totalsize; i++) {
            cout << i << " --> ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << "(" << temp->key << "," << temp->value << ") -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    void remove(string key) {
        int idx = hashfunction(key);
        Node* temp = table[idx];
        Node* prev = NULL;

        while (temp != NULL) {
            if (temp->key == key) {
                if (prev == NULL) {
                    table[idx] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                temp->next = NULL; // avoid recursive delete
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    ~HashTable() {
        for (int i = 0; i < totalsize; i++) {
            if (table[i] != NULL) {
                delete table[i];
            }
        }
        delete[] table;
    }
};

int main() {
    HashTable ht;

    ht.insert("india", 100);
    ht.insert("china", 200);
    ht.insert("us", 300);
    ht.insert("nepal", 400);
    ht.insert("uk", 500);

    ht.remove("china");

    ht.printTable();

    return 0;
}
