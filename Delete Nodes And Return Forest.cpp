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
    vector<TreeNode*> ans;
    void dfs(TreeNode* &root,unordered_set<int> & st){
        if(root){
            dfs(root->left,st);
            dfs(root->right,st);
            if(st.find(root->val)!=st.end()){
                if(root->left)ans.push_back(root->left);
                if(root->right)ans.push_back(root->right);
                root=NULL;
            }
            
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(),to_delete.end());
        set<int> ::iterator itr;
        for(auto itr=st.begin();itr!=st.end();itr++){
            cout<<*itr;
        }
        dfs(root,st);
        if(root)ans.push_back(root);
        return ans;
        
    }
};