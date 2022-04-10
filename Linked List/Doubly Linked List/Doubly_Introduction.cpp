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

int main(){
    ListNode* head = new ListNode(10);
    ListNode* middle = new ListNode(20);
    ListNode* tail = new ListNode(30);

    head->next = middle;
    middle->prev = head;
    middle->next = tail;
    tail->prev = middle;

    printList(head);
}
