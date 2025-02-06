// void insertAtPos(Node* &head, int val, int pos) {
//     if(pos == 0) {
//         insertAtHead(head, val);
//         return;
//     }
//     Node* newNode = new Node(val);

//     Node* temp = head;
//      int curr_pos = 0;
//      while(curr_pos != pos-1) {
//         temp = temp->next;
//         cur_pos++;
//      }

//      // temp is pointing to node ar pos-1
//     newNode->next = temp->next;
//     temp->next = newNode;
//   }


