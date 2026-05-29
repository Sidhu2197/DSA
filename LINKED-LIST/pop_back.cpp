#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* head = NULL;

void pop_back() {
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

void printList() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    // manually creating list: 10 -> 20 -> 30
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    printList();   // before deletion

    pop_front();

    printList();   // after deletion
}