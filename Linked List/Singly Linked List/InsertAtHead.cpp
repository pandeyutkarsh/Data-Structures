void InsertAtHead(Node* &head,Node* &tail,int data){

    // Creating a new node
    Node* newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
