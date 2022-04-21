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
    }
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

    ListNode* newNode = new ListNode(data);

 if(head == NULL){
     return;
 }else{

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


ListNode* remove(ListNode* &head){
 
 if(head == NULL){
     return NULL;
 }

ListNode* curr = head;

 while(curr != NULL){


     if((curr->next != NULL) && (curr->data == curr->next->data)){
        ListNode* next_next = curr->next->next;
        ListNode* nodeToDelete = curr->next;
        delete(nodeToDelete);
        curr->next = next_next; 
     }else{
         curr = curr->next;
     }
 }
return head;
}


int main(){

  ListNode* head = NULL;
    InsertAtHead(head,2);
    InsertAtHead(head,10);
    InsertAtHead(head,0);
    InsertAtTail(head,2);
    InsertAtTail(head,2);
    InsertAtTail(head,2);
    InsertAtPosition(head,-30,3);

    // insertCycle(head);

    // cout<<FloyedCircle(head)->data<<endl;
    // cout<<getFirstNode(head)->data<<endl;
    // removeLoop(head);
    head = remove(head);
    printList(head);

}
