struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* temp;
    struct ListNode* curr=head;
    struct ListNode* prev=NULL;
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct ListNode* newHead=head->next;
    while(curr!=NULL && curr->next!=NULL){
        if(prev!=NULL){
            prev->next=curr->next;
        }
        prev=curr;
        temp=curr->next->next;
        curr->next->next=curr;
        curr->next=temp;
        curr=temp;
    }
    return newHead;
}
