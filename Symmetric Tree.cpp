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
    bool mirror(TreeNode*lef,TreeNode*righ){
        if(lef==NULL && righ==NULL) return true;
        if(lef==NULL || righ==NULL) return false;
        return lef->val==righ->val &&mirror(lef->left,righ->right) &&mirror(lef->right,righ->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return mirror(root->left,root->right);
        
    }
};