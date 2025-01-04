/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> vec;
        queue<TreeNode*>queue;
        if(!root) return {};
        queue.push(root);
        while(!queue.empty()){
            int s=queue.size();
            int val=INT_MIN;
            for(int i=0;i<s;i++){
                TreeNode*temp=queue.front();
                queue.pop();
                val=max(val,temp->val);
                if(temp->left)queue.push(temp->left);
                if(temp->right)queue.push(temp->right);
            }
            vec.push_back(val);
        }
        return vec;
        
    }
};