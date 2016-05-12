struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* node1=head;
    struct ListNode* node2=head;
    while(n--){
        if(node2->next==NULL)
            return head->next;
        else
            node2=node2->next;
    }
    while(node2->next!=NULL){
        node1=node1->next;
        node2=node2->next;
    }
    node1->next=node1->next->next;
    return head;
}