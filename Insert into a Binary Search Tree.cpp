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
    TreeNode* search(TreeNode*root,int val){
        if(!root){
            TreeNode* root=new TreeNode(val);
            return root;
        }
        if(root->val<val) root->right=search(root->right,val);
        else root->left=search(root->left,val);
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return search(root,val);
        


        
    }
};