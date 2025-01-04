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
    TreeNode* build(vector<int>&nums,int l,int r){
        if(l>r)return NULL;
        int mid=ceil((l+r)/2);
        TreeNode*root=new TreeNode(nums[mid]);
        root->left=build(nums,l,mid-1);
        root->right=build(nums,mid+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int a=0;
        int b=1;
        int c=(a+b)/2;
        cout<<c;
        return build(nums,0,nums.size()-1);

        
    }
};