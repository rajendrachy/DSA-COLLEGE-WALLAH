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
};

int main()
{

   Node *new_node = new Node(3);
   DoublyLinkedList ddl;
   ddl.head = new_node;
   ddl.tail = new_node;
   cout << ddl.head->val << endl;
   return 0;
}