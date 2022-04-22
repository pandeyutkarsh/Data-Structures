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


ListNode* remove(ListNode* head){
 
 if(head == NULL){
     return NULL;
 }

ListNode* curr = head;

while(curr != NULL){
    // cout<<"got it\n";
    if(curr->next != NULL){
        ListNode* temp = curr->next;
        ListNode* prev = curr;
        while(temp != NULL){
            if(curr->data == temp->data){
                prev->next = prev->next->next;
                temp = prev->next;
                // cout<<"got\n";
            }else{
                prev = temp;
                temp = temp->next;
            }
            
        }
    }
    curr = curr->next;
}

return head;
}


int main(){

  ListNode* head = NULL;
//     InsertAtHead(head,2);
//     InsertAtHead(head,10);
//     InsertAtHead(head,0);
//     InsertAtTail(head,2);
//     InsertAtTail(head,2);
//     InsertAtTail(head,2);
//     InsertAtPosition(head,-30,3);
InsertAtHead(head,2);
InsertAtHead(head,20);
InsertAtHead(head,26);
InsertAtHead(head,20);
InsertAtHead(head,89);
InsertAtHead(head,2);
InsertAtHead(head,6);
InsertAtHead(head,2);
InsertAtHead(head,89);
printList(head);
    // insertCycle(head);

    // cout<<FloyedCircle(head)->data<<endl;
    // cout<<getFirstNode(head)->data<<endl;
    // removeLoop(head);
    head = remove(head);
    printList(head);

}
