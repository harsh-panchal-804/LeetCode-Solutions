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
    void preorder(TreeNode*root,int &count,int &candidate,vector<int>&ans,int & maxcount){
        if(!root)return;
        preorder(root->left,count,candidate,ans,maxcount);
        if(root->val==candidate)count++;
        else count=1;
        if(count>maxcount){
            maxcount=count;
            ans.clear();
            ans.push_back(root->val);
        }
        else if(count==maxcount)ans.push_back(root->val);
        candidate=root->val;
        
        preorder(root->right,count,candidate,ans,maxcount);
        


    }
    vector<int> findMode(TreeNode* root) {
        int count=0;
        int candidate=0;
        int maxcount=0;
        vector<int> ans;
        preorder(root,count,candidate,ans,maxcount);
        return ans;
        
    }
};