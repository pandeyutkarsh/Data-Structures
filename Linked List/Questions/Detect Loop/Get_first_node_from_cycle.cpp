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

void insertCycle(ListNode* &head){


  
    
       ListNode* temp = head;
       ListNode* prev = NULL;
       while(temp != NULL){
           prev = temp;
           temp = temp->next;
       }
        prev->next = head->next;  
    

 }

ListNode* FloyedCircle(ListNode* head){

if(head == NULL) return NULL;

ListNode* slow = head;
ListNode* fast = head;

while(slow != NULL && fast != NULL){
  fast = fast->next;
  if(fast != NULL){
      fast = fast->next;
  }

  slow = slow->next;

  if(slow == fast){
      return slow;
  }
}

return NULL;

}

ListNode* getFirstNode(ListNode* head){

ListNode* intersection = FloyedCircle(head);
ListNode* slow = head;

while(slow != intersection){
    slow = slow ->next;
    intersection = intersection ->next; 
}

return slow;

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

    insertCycle(head);

    cout<<FloyedCircle(head)->data<<endl;
    cout<<getFirstNode(head)->data<<endl;
    // printList(head);

}
