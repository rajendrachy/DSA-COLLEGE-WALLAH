// ------------Delete at the Arbitrary Position--------------------
// -------------Delete a Node at the End----------------------
// ------------Delete a Node at the Start------------------------
#include <iostream>
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

// --------Delete at The Start------------------
void deleteAtHead(Node*& head) {
    if (head == NULL) return; // Handle empty list case
    Node* temp = head; // Node to be deleted
    head = head->next;
    delete temp;
}

// --------Delete at Arbitrary Position---------------------
void deleteAtPos(Node*& head, int pos) {
    if (head == NULL || pos < 0) return; // Handle empty list or invalid position

    if (pos == 0) { // If position is 0, delete at head
        deleteAtHead(head); // TC -> O(n)
        return;
    }

    Node* prev = head;
    int curr_pos = 0;

    while (prev->next != NULL && curr_pos < pos - 1) { // Traverse to node before the target
        prev = prev->next;
        curr_pos++;
    }

    if (prev->next == NULL) return; // If position is out of bounds

    Node* temp = prev->next;
    prev->next = temp->next;
    delete temp;
}


// -------------Traverse-----------
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << "-";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Before Deletion: ";
    display(head);

    deleteAtPos(head, 2); // Delete node at position 1

    cout << "After Deletion: ";
    display(head);

    return 0;
}


