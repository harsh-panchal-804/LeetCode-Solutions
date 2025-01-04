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
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return head;
        ListNode* prev=head;
        ListNode* curr=head->next;
        int sum=0;
        while(curr){
            if(curr->val!=0){
                sum+=curr->val;
            }
            else{
                curr->val=sum;
                sum=0;
                prev->next=curr;
                prev=curr;
            }
            curr=curr->next;
        }
        return head->next;
    }
};