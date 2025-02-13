// -------------Delete a Node at the End----------------------
// ------------Delete a Node at the start------------------------
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

// --------delete at The Start------------------
void deleteAtHead(Node*& head) { // Time-Complexicity -> O(1)
   if (head == NULL) return; // Handle empty list case
   Node* temp = head; // Node to be deleted
   head = head->next; 
   //free(temp); // or,
   delete temp;
}

// ----------delete at Tail--------------------
void deleteAtTail(Node* &head) { // Time-complexicity ->O(n)
    Node* sLast = head;
    while(sLast->next->next != NULL) {
        sLast = sLast->next;
    }
    
    //Now secondlast point to secondlast nose
    Node* temp = sLast->next;
    sLast->next = NULL;

}


// -------------traverse-----------
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

    cout << "Before deletion: ";
    display(head);

    deleteAtHead(head);
    
    cout << "After deletion: ";
    display(head);

    deleteAtTail(head);
    display(head);

    return 0;
}
