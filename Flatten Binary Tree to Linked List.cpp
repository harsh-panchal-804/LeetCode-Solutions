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
    void preorder(TreeNode*root,vector<TreeNode*>&vec){
        if(root){
            vec.push_back(root);
            preorder(root->left,vec);
            preorder(root->right,vec);
        }
    }
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        vector<TreeNode*> vec;
        preorder(root,vec);
        for(auto i: vec){
            cout<<i->val;
        }
        vec.back()->right=NULL;
        for(int i=vec.size()-2;i>=0;i--){
            vec[i]->right=vec[i+1]; 
            vec[i]->left=NULL;       
        }
        
        
    }
};