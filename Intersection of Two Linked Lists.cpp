/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la=0;
        int lb=0;
        ListNode* tempa=headA;
        ListNode* tempb=headB;
       

        while(headA){
            la++;
            headA=headA->next;
        }
        while(headB){
            lb++;
            headB=headB->next;
        }
        cout<<la<<lb;
        if(la-lb<=0){/// a is smaller
            for(int i=0;i<abs(la-lb);i++){
                tempb=tempb->next;
            }
        }
        else{
            for(int i=0;i<abs(la-lb);i++){
                tempa=tempa->next;
            }
        }
        while(tempa != tempb){
            tempa=tempa->next;
            tempb=tempb->next;
        }
        
        return tempa;
        
    }
};