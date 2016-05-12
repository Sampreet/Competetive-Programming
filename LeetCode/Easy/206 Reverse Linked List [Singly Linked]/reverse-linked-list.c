/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL){
        return NULL;
    }
    struct ListNode* current=head,*temp=head;
    head=head->next;
    current->next=NULL;
    temp=current;
    while(head!=NULL){
        current=head;
        head=head->next;
        current->next=temp;
        temp=current;
    }
    return current;
}
