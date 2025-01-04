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
    int curr=0;
   
    TreeNode* dfs(TreeNode* root){
        if(!root)return nullptr;
        dfs(root->right);
        curr+=root->val;
        root->val=curr;
        dfs(root->left);
        return root;

    }
    TreeNode* bstToGst(TreeNode* root) {
        return dfs(root);
        
    }
};