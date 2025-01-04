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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* save=head;
        while(head && head->next){
            int val=__gcd(head->val,head->next->val);
            ///ListNode* nxt=head->next->next;
            ListNode* temp=new ListNode(val);
            temp->next=head->next;
            head->next=temp;
            head=temp->next;
            
        }
        return save;

        
    }
};