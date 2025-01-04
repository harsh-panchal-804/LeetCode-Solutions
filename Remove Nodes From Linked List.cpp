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
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> stack;
        vector<ListNode*> nums;
        while(head){
            nums.push_back(head);
            head=head->next;
        }
        for(auto i : nums){
            if(!stack.empty()&&i->val >stack.back()->val){
            while(!stack.empty()&&i->val >stack.back()->val){
                stack.pop_back();
            }
            stack.push_back(i);
            }
            else {
                stack.push_back(i);
            }
        }
        if(stack.empty()) return NULL;
        stack.back()->next=NULL;
        for(int i=stack.size()-2;i>=0;i--){
            stack[i]->next=stack[i+1];
        }
        return stack[0];
      
        ///for(auto i : stack) cout<<i->val;
        return NULL;
        
    }
};