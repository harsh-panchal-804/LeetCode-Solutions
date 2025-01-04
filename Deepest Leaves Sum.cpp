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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> queue;
        int ans;
        queue.push(root);
        while(!queue.empty()){
            int s=queue.size();
            int sum=0;
            while(s--){
                TreeNode* temp=queue.front();
                queue.pop();
                sum+=temp->val;
                if(temp->right)queue.push(temp->right);
                if(temp->left)queue.push(temp->left);
            }
            if(queue.empty())ans=sum;
        }
        return ans;
        
    }
};