struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry=l1->val+l2->val;
    struct ListNode* head=l1;
    l1->val=carry%10;
    carry/=10;
    while(l1->next!=NULL && l2->next!=NULL){
        l1=l1->next;
        l2=l2->next;
        carry+=l1->val+l2->val;
        l1->val=carry%10;
        carry/=10;
    }
    if(l1->next==NULL && l2->next!=NULL){
        l1->next=l2->next;
    }
    while(l1->next!=NULL){
        l1=l1->next;
        carry+=l1->val;
        l1->val=carry%10;
        carry/=10;
    }
    if(carry!=0){
        struct ListNode* newNode;
        newNode->val=carry;
        newNode->next=NULL;
        l1->next=newNode;
    }
    return head;
}