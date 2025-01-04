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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length=0;
        ListNode* temp=head;
        while(temp){
            length++;
            temp=temp->next;
        }
        int parts=length/k;
        int extra=length%k;
        ListNode* prev=nullptr;
        vector<ListNode*> ans(k,NULL);
        ListNode* curr=head;
        for(int p=0;p<k&& curr;p++){
            ans[p]=curr;
            int curr_size=parts+(p<extra?1:0);
            for(int j=0;j<curr_size;j++){
                prev=curr;
                curr=curr->next;
            }
            if(prev)prev->next=nullptr;

        }
        return ans;


        
    }
};