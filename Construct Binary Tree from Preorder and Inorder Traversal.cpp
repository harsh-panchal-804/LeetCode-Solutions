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
    TreeNode* build(vector<int>& preorder,vector<int>&inorder){
        if(inorder.size()==0 || preorder.size()==0)return NULL;
        TreeNode* root=new TreeNode(preorder[0]);
        int mid=0;
        while(inorder[mid]!=preorder[0]){
            mid++;
        }
        vector<int> preordernl(preorder.begin()+1,preorder.begin()+mid+1);
        vector<int> preordernr(preorder.begin()+mid+1,preorder.end());
        vector<int> inorderl(inorder.begin(),inorder.begin()+mid);
        vector<int> inorderr(inorder.begin()+mid+1,inorder.end());
        root->left=build(preordernl,inorderl);
        root->right=build(preordernr,inorderr);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder);
        
    }
};