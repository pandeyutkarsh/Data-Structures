
void reverse(ListNode* &head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* forward = NULL;

    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    head = prev;

}

