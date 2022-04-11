void helper(ListNode* &head,ListNode* curr,ListNode* prev) {

    if(curr == NULL){
        head = prev;
        return;
    }

    ListNode* forward = curr -> next;
    curr->next = prev;
    prev = curr;
    curr = forward;  
    helper(head,curr,prev);
}

void reverse(ListNode* &head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* forward = NULL;

    helper(head,curr, prev);
}
