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
    void dfs(TreeNode*root,int target,int curr,vector<int>ans,vector<vector<int>>&fans)
    {
        if(!root){
            return;
        }
        curr+=root->val;
        ans.push_back(root->val);
        if(!root->left && !root->right&& curr==target){
            fans.push_back(ans);
            return;
        }
        dfs(root->left,target,curr,ans,fans);
        dfs(root->right,target,curr,ans,fans);
        curr-=root->val;
        ans.pop_back();
        return;
       
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> fans;
        vector<int> ans;
        if(!root) return fans;
        dfs(root,targetSum,0,ans,fans);
        return fans;

        
    }
};