// Implementation of Singly Linked List with its operations

#include <iostream>
using namespace std;

/* 
Creating a class Node -> which contains:
1. An integer data part named data
2. A pointer next which stores the address of the next node in the linked list.
*/
class Node
{
public:
    int data;
    Node *next;

    /* Constructor: Initializes the node with given data and sets the next pointer to NULL */
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

/* 
Class LinkedList: Manages all linked list operations.
*/
class LinkedList
{
public:
    Node *head; // Pointer to the first node of the linked list

    /* Constructor: Initializes an empty linked list */
    LinkedList()
    {
        head = NULL;
    }

    /* 
    insertBegin(int data): Inserts a new node at the beginning of the linked list.
    Cases:
    1. If the linked list is empty -> The new node becomes the head.
    2. Otherwise -> The new node points to the current head, and then head is updated.
    */
    void insertBegin(int data)
    {
        // Creating a new node
        Node *newNode = new Node(data);

        // If the list is empty, set head to newNode
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        // Otherwise, insert at the beginning
        newNode->next = head;
        head = newNode;
    }

    /* 
    traverse(): Displays all elements in the linked list.
    Cases:
    1. If the linked list is empty -> Print "LINKED LIST IS EMPTY".
    2. Otherwise -> Iterate through the list and print each element.
    */
    void traverse()
    {
        Node *temp = head;

        if (head == NULL)
        {
            cout << "LINKED LIST IS EMPTY\n";
            return;
        }

        // Traverse through the list
        while (temp != NULL)
        {
            cout << temp->data << "--->";
            temp = temp->next;
        }
        cout << "NULL\n"; // Indicating end of the list
    }

    /* 
    insertEnd(int data): Inserts a new node at the end of the linked list.
    Cases:
    1. If the list is empty -> The new node becomes the head.
    2. Otherwise -> Traverse to the last node and insert the new node.
    */
    void insertEnd(int data)
    {
        Node *newNode = new Node(data);

        // If the list is empty, new node becomes the head
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        // Traverse to the last node
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = newNode;
    }

    /* 
    insertafterposition(int data, int pos): Inserts a node after a given position.
    Cases:
    1. If pos == 0 -> The node is inserted at the beginning.
    2. If the position is valid -> Insert the new node at the given position.
    3. If position is invalid (greater than list size) -> Print "INVALID POSITION".
    */
    void insertafterposition(int data, int pos)
    {
        if (pos == 0)
        {
            insertBegin(data);
            return;
        }

        Node *newNode = new Node(data);
        Node *temp = head;
        int i = 1;

        // Traverse to the desired position
        while (i < pos && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        // If position is invalid
        if (temp == NULL)
        {
            cout << "INVALID POSITION" << endl;
            return;
        }

        // Insert the node after the given position
        newNode->next = temp->next;
        temp->next = newNode;
    }

    /* 
    deletebegin(): Deletes the first node from the linked list.
    Cases:
    1. If the list is empty -> Print "LINKED LIST DOES NOT EXIST".
    2. Otherwise -> Update head to the second node and delete the first node.
    */
    void deletebegin()
    {
        if (head == NULL)
        {
            cout << "LINKED LIST DOES NOT EXIST" << endl;
            return;
        }

        Node *temp = head;
        head = head->next; // Move head to the next node
        delete temp;       // Delete the old head
    }

    /* 
    deleteend(): Deletes the last node from the linked list.
    Cases:
    1. If the list is empty -> Print "DELETION CANNOT BE DONE".
    2. If there is only one node -> Delete the head.
    3. Otherwise -> Traverse to the second-last node and delete the last node.
    */
    void deleteend()
    {
        if (head == NULL)
        {
            cout << "DELETION CANNOT BE DONE" << endl;
            return;
        }

        // If there's only one element in the list
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        // Traverse to the second-last node
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        // Delete the last node
        Node *temp2 = temp->next;
        temp->next = NULL;
        delete temp2;
    }

    /* 
    deleteafterpos(int pos): Deletes a node after a given position.
    Cases:
    1. If the list is empty -> Print "LINKED LIST IS EMPTY".
    2. If the position is valid and a node exists -> Delete the node.
    3. If position is invalid (greater than list size) -> Print "Invalid Index".
    */
    void deleteafterpos(int pos)
    {
        if (head == NULL)
        {
            cout << "\nLINKED LIST IS EMPTY ";
            return;
        }

        int i = 1;
        Node *temp = head;

        // Traverse to the given position
        while (i < pos && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        // If position is invalid or there is no node to delete
        if (temp == NULL || temp->next == NULL)
        {
            cout << "Invalid Index ";
            return;
        }

        // Delete the node
        Node *del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
};

/* 
Main Function: Testing the linked list operations
*/
int main()
{
    LinkedList l;

    // Inserting elements at the beginning
    l.insertBegin(10); // 10
    l.insertBegin(20); // 20-->10
    l.insertBegin(30); // 30-->20-->10

    // Display the list
    l.traverse();
    cout << endl;

    // Trying to delete after an invalid position (should print "Invalid Index")
    l.deleteafterpos(6);
    cout << endl;

    // Deleting the node after position 1 (removes node 10)
    l.deleteafterpos(1);
    
    // Display the list again
    l.traverse();
   return 0;
}