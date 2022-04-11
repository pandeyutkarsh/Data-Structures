#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode* next;

    ListNode(int data){
        this->data = data;
        this->next = NULL;
    } 

    ~ListNode() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }   
};

int Peek(ListNode* head){
    ListNode* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    return count;
}

void printList(ListNode* node){
    while(node != NULL){
        cout<<node->data<<" ";
        node = node->next;
    }cout<<"\n";
}

void InsertAtHead(ListNode* &head,int data){

    ListNode* node = new ListNode(data);
    if(head == NULL){
        head = node;
    }else{
        node->next = head;
        head = node;
    }
}

void InsertAtTail(ListNode* &head,int data){
     ListNode* node = new ListNode(data);
    if(head == NULL){
        head = node;
    }else{
       ListNode* temp = head;
       ListNode* prev = NULL;
       while(temp != NULL){
           prev = temp;
           temp = temp->next;
       }
        prev->next = node;  
    }
}

void InsertAtPosition(ListNode* &head,int data,int pos){

 if(head == NULL){
     return;
 }else if(pos == 1){
        InsertAtHead(head,data);
 }else{
     ListNode* newNode = new ListNode(data);
     int cnt = 1;
     ListNode* node = head;
     while(node != NULL){
         if(cnt == pos-1){
             break;
         }
         cnt++;
         node = node->next;
     }

     ListNode* forward = node->next;
     node->next = newNode;
     newNode->next = forward;

 }
}


void Delete(ListNode* &head,int pos){
    if(head == NULL){
        return;
    }else if(pos == 1){
       ListNode* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }else{

     int cnt = 1;
     ListNode* curr = head;
     ListNode* prev = NULL;
      while(cnt < pos) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

   prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}


ListNode* reverse(ListNode* &head,int k){

    // base case
    if(head == NULL){
        return NULL;
    }

    // step 1 : reverse first k nodes
    ListNode* next = NULL;
    ListNode* curr = head;
    ListNode* prev = NULL;
    int cnt = 0;
    while(curr != NULL && cnt < k){
        next = curr->next;
        curr -> next  = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    // step 2 : recursion
    if(next != NULL){
        head->next = reverse(next,k);
    }

    // step 3 : return head of reversed list
    return prev;
}

int main(){

  ListNode* head = NULL;
    InsertAtHead(head,20);
    InsertAtHead(head,10);
    InsertAtHead(head,0);
    InsertAtTail(head,-1);
    InsertAtTail(head,-2);
    InsertAtTail(head,-3);
    InsertAtPosition(head,-30,3);
    // printList(head);
    // Delete(head,3);
    printList(head);

    head = reverse(head,2);
//    cout<<Peek(head)/2<<endl;

    printList(head);



}
