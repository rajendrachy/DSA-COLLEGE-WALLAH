#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class SingleLL
{
public:
    Node *head;
    SingleLL()
    {
        head = NULL;
    }

    void insertLast(int data)
    {
        // create node
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertBegin(int data)
    {
        // create a new node
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void traverse()
    {
        if (head == NULL)
        {
            cout << "LINKED LIST IS EMPTY";
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
    }

    //You have to write function of insertion at the middle of linked list in which user specified the position at which he/she wants to insert a node
    // for example - 10-->20-->30-->60
    // you have to add 99 after 2nd node
    // then the linked list will be 10-->20-->99-->30-->60.


//Solution of the above question
// add the following function inside LinkedList Class

void insertmiddle(int data, int pos)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
};

int main()
{
    SingleLL l;
    l.traverse();

    l.insertBegin(10);
    cout << endl;
    l.traverse();

    l.insertBegin(20);
    cout << endl;
    l.traverse();

    l.insertBegin(30);
    cout << endl;
    l.traverse();

    l.insertLast(1000);
    cout << endl;
    l.traverse();

    return 0;
}