
void InsertAtTail(Node* &head,Node* &tail,int data){
    
     // Creating a new node
    Node* newNode = new Node(data);

    if(tail == NULL){
        head = newNode;
        tail = newNode;
    }else{
         tail->next = newNode;
         tail = newNode;
    }
}

