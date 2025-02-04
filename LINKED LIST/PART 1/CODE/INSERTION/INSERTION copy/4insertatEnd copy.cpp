#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL; // NULL => 0(Zero)
    }
};

// ------------Insert at the End(i.e tail)--------------
void insertAtTail(Node* &head, int val) { // TC -> O(1)
    Node* newNode = new Node(val);
    
    if (head == NULL) {  // If the list is empty, make newNode the head
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    // temp has reached the last node
    temp->next = newNode;
}

// -------------traverse-----------
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << '-';
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    
    // Insert elements at the tail
    insertAtTail(head, 3);
    display(head);
    
    insertAtTail(head, 1);
    display(head);

    return 0;
}

