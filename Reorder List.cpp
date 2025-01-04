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
    void reorderList(ListNode* head) {
        vector<ListNode*>ll;
        vector<ListNode*>newll;
        while(head){
            ll.push_back(head);
            head=head->next;
        }
        int n=ll.size();
        // cout<<n;
        // cout<<endl;   
        for(int i=0;i<ll.size()/2;i++){
            newll.push_back(ll[i]);
            newll.push_back(ll[n-i-1]);
            
        }
        if(n%2==1) newll.push_back(ll[n/2]);
        // for(auto i : newll){
        //     cout<<i->val<<" ";
        // }
        newll.back()->next=NULL;
        for(int i=newll.size()-2;i>=0;i--){
            newll[i]->next=newll[i+1];
        }

        // cout<<endl;
        // cout<<newll.size();
        
        
    }
};