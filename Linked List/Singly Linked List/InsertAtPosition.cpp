void InsertAtPosition(Node* &head,Node* &tail,int data,int pos){

        if(pos == 1){
            InsertAtHead(head,tail,data);
            return;
        }

        // Creating a node
        Node* newNode = new Node(data);

        Node* temp = head;
        int cnt = 1;

        while(cnt < pos-1){
            temp = temp->next;
            cnt++;
        }

        // inserting at tail
        if(temp->next == NULL){
            InsertAtTail(head,tail,data);
            return;
        }

        newNode -> next = temp->next;
        temp->next = newNode;
}
