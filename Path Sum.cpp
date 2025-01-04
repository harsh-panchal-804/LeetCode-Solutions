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
    bool dfs(TreeNode* root,int targetSum,int cur){
        if(root==NULL){
            return false;
        }
        cur+=root->val;
        if(root->left==NULL && root->right==NULL){
            return targetSum==cur;
        }
        return dfs(root->left,targetSum,cur) || dfs(root->right,targetSum,cur);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,targetSum,0);
        
    }
};