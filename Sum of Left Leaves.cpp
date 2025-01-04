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
    int dfs(TreeNode*root,int sum,bool flag){
        if(!root) return 0;
        if(!root->left&&!root->right){
            if(flag==true){
                sum+=root->val;
            }
            else sum+=0;
        }
        sum+=dfs(root->left,sum,true)+dfs(root->right,sum,false);
        return sum;

    }
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root,0,false);
        
    }
};