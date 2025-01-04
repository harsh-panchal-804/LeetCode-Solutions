/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root,TreeNode* p,vector<TreeNode*> &s){
        if(!root)return false;
        s.push_back(root);
        if(root==p)return true;
        bool left=dfs(root->left,p,s);
        bool right=dfs(root->right,p,s);
        if(left || right)return true;
        s.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a;
        vector<TreeNode*> b;
        dfs(root,p,a);
        dfs(root,q,b);
        int i=0;
        while(i<min(a.size(),b.size())){
            if(a[i]!=b[i]){
                break;
            }
            ++i;
        }
        
        return a[i-1];
    }
};