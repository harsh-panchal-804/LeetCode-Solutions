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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());
        int ans=0;
        while(head){
            if(set.count(head->val)>0){
                while(head &&set.count(head->val)>0){
                    head=head->next;
                }
                ans++;
            }
            if(head!=nullptr) head=head->next;
        }
        return ans;
        
    }
};