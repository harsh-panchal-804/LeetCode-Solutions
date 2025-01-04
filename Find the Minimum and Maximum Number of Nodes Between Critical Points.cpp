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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> index;
        ListNode* curr=head->next;
        ListNode* prev=head;
        int ind=1;
        while(curr && curr->next){
            if((curr->val>prev->val && curr->val>curr->next->val) || (curr->val<prev->val && curr->val<curr->next->val)){
                index.push_back(ind);
            }
            prev=curr;
            curr=curr->next;
            ++ind;
        }
        for(auto i : index){
            cout<<i<<" ";
        }
        if(index.size()<2){
            return {-1,-1};
        }
        int m=INT_MAX;
        for(int i=1;i<index.size();i++){
            m=min(m,index[i]-index[i-1]);
        }

        return {m,index.back()-index[0]};
        
    }
};