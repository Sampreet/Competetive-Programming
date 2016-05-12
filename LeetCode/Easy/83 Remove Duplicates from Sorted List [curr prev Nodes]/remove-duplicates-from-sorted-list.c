/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct ListNode* prev=head;
    struct ListNode* curr=head->next;
    prev->next=NULL;
    while(curr!=NULL){
        if(curr->val==prev->val){
            curr=curr->next;
        }
        else{
            prev->next=curr;
            prev=prev->next;
            curr=curr->next;
            prev->next=NULL;
        }
    }
    return head;
}
