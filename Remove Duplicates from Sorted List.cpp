/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* h=head;
        
        while(curr!=NULL){
            if(curr->val==prev->val){
                while(curr!=NULL&&prev->val==curr->val){
                    curr=curr->next;
                }  
                prev->next=curr;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return h;
        
    }
};