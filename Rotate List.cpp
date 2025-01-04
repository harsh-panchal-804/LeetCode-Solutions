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
    ListNode* rotateRight(ListNode* head, int k) {
        deque<ListNode*> deq;
        if(head==NULL) return NULL;
        while(head!=NULL){
            deq.push_back(head);
            head=head->next;
        }
        for(int i=0;i<k%deq.size();i++){
            ListNode* temp=deq.back();
            deq.pop_back();
            deq.push_front(temp);
        }
        deq.back()->next=NULL;
        for(int i=deq.size()-2;i>=0;i--){
            deq[i]->next=deq[i+1];
        }

        return deq[0];
        
    }
};