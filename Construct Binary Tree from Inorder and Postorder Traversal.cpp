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
    TreeNode* build(vector<int>& inorder,vector<int>&postorder){
        if(inorder.size()==0|| postorder.size()==0){
            return NULL;
        }
        int mid=0;
        while(inorder[mid]!=postorder.back())mid++;
        TreeNode* root= new TreeNode(postorder.back());
        postorder.pop_back();
        vector<int> inorderl(inorder.begin(),inorder.begin()+mid);
        vector<int> inorderr(inorder.begin()+mid+1,inorder.end());
        root->right=build(inorderr,postorder);
        root->left=build(inorderl,postorder);
      
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder,postorder);
        
    }
};