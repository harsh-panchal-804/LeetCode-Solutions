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
    string ans="~";
    string dfs(TreeNode*root,string path){
        if(!root)return"";
        path=char('a'+root->val)+path;
        if(!root->left && !root->right){
            ans=min(ans,path);
        }
        dfs(root->left,path);
        dfs(root->right,path);
        return ans;
        
    }
    string smallestFromLeaf(TreeNode* root) {
        
        return dfs(root,"");
        
    }
};