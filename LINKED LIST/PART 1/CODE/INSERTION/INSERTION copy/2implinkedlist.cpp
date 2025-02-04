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

int main() {
      Node* n = new Node(1);
      cout << n->val << " " << n->next << endl;
    return 0;
}

