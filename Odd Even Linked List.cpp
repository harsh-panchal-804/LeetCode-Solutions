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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr=head;
        ListNode* odd=head;
        ListNode* evensave=head->next;
        ListNode* even=head->next;
        while(even && even->next){
            odd->next=odd->next->next;
            odd=odd->next;
            even->next=even->next->next;
            even=even->next;
        }
        // while(head->next){
        //     head=head->next;
        // }
        odd->next=evensave;
        return head;
       
       
        
    }
};