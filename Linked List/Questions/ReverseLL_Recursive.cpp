    ListNode* reverse(ListNode* head){
    
    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode* SmallHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return SmallHead;
}
