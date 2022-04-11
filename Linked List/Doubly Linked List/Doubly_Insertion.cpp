#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
        ListNode* prev;
        int data;
        ListNode* next;

        ListNode(int data){
            this->prev = NULL;
            this->data = data;
            this->next = NULL;
        }
};

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
        head->prev = node;
        head = node;
    }
}

void InsertAtTail(ListNode* &head,int data){
    
    ListNode* node = new ListNode(data);

    if(head == NULL){
        head = node;
    }else{
        ListNode* temp = head;
       while(temp->next != NULL){
           temp = temp->next;
       }

       node->prev = temp;
       temp->next = node;
    }
}

void InsertAtPosition(ListNode* &head,int data,int pos){
    ListNode* node = new ListNode(data);
    if(head == NULL){
        head = node;
    }else if(pos == 1){
        InsertAtHead(head,data);
    }else{
        ListNode* curr = head;
        ListNode* prev = NULL;
        int cnt = 1;
        while(cnt < pos){
            cnt++;
            prev = curr;
            curr = curr->next;
        }

        prev->next = node;
        node->prev = prev;
        node->next = curr;
        curr->prev = node;




    }
}


int main(){
    ListNode* head = NULL;

    InsertAtHead(head,30);
    InsertAtHead(head,20);
    InsertAtHead(head,10);
    InsertAtTail(head,40);
    InsertAtTail(head,50);
    InsertAtPosition(head,-1,3);
    

    printList(head);
}
