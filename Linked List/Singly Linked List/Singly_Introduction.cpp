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

void printList(ListNode* node){
    while(node != NULL){
        cout<<node->data<<" ";
        node = node->next;
    }
}

int main(){

    ListNode* head = new ListNode(1);
    ListNode* middle = new ListNode(2);
    ListNode* tail = new ListNode(3);

    head->next = middle;
    middle->next = tail;

    printList(head);

}
