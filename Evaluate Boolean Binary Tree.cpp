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
    bool evaluate(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            if(root->val==1) return true;
            else return false;
        }
        if(root->val==2){
              root->val=(bool)evaluate(root->left) || (bool)evaluate(root->right);
        }
        else{
            root->val=(bool)evaluate(root->left) && (bool)evaluate(root->right);
        }
        return root->val;
    }
    bool evaluateTree(TreeNode* root) {
        return evaluate(root);

    }
};