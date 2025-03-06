//-----Implement double linkedList---------------------------

#include <iostream>
using namespace std;

class Node
{
public:
   int val; // It could be char, int, bool, long int
   Node *prev;
   Node *next;

   Node(int data)
   {
      val = data;
      prev = NULL;
      next = NULL;
   }
};


class DoublyLinkedList
{
public:
   Node *head;
   Node *tail;

   DoublyLinkedList()
   {
      head = NULL;
      tail = NULL;
   }

   void insertAtStart(int val) {
    Node* new_node = new Node(val); // Creating a New Node

    // Checking the linked list is empty or not
    if(head == NULL) {
      head = new_node;
      tail = new_node;
      return;
    }

    new_node->next = head; // 
    head->prev = new_node;
    head = new_node;
 }

 void display() {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->val << "<->";
        temp = temp->next;
    }
    cout << endl;
 }
};


int main()
{ 
   DoublyLinkedList ddl;
   ddl.insertAtStart(1);
   ddl.display();
   ddl.insertAtStart(2);
   ddl.display();
   ddl.insertAtStart(3);
  ddl.display();
   return 0;
}


