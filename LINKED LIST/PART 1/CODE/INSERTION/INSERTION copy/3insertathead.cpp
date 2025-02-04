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

//----------Insert at the Beginning (i.e Head)---------------
void insertAtHead(Node* &head, int val) { // Time Complexicity => O(1)
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
};
// -------------traverse-----------
void display(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->val << '-';
        temp = temp->next;
    }
    cout << "NULL" << endl;

}

int main() {
    Node* head = NULL;
    insertAtHead(head, 2);
    display(head);
    insertAtHead(head, 1);
    display(head);
    return 0;
}

