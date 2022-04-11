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

void reverse(ListNode* &head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* forward = NULL;
    int cnt = Peek(head)/2;

    while(cnt > 0) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        cnt--;
    }

    head->next = forward;
    head = prev;

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

    reverse(head);

    printList(head);



}
