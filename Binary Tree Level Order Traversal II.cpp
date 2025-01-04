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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vec;
        if(root==NULL) return vec;
        queue<TreeNode*>queue;
        queue.push(root);
        while(!queue.empty()){
            int size=queue.size();
            vector<int>curr;
            for(int i=0;i<size;i++){
                TreeNode* temp=queue.front();
                queue.pop();
                curr.push_back(temp->val);
                if(temp->left) queue.push(temp->left);
                if(temp->right)queue.push(temp->right);
            }
            vec.push_back(curr);
        }
        reverse(vec.begin(),vec.end());
        return vec;
        
    }
};