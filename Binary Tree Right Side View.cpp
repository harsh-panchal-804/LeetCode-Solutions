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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> vec;
        queue<TreeNode*>queue;
        queue.push(root);
        while(!queue.empty()){
            int s=queue.size();
            vector<int> curr;
            for(int i=0;i<s;i++){
                TreeNode* temp=queue.front();
                queue.pop();
                if(temp->left)queue.push(temp->left);
                if(temp->right)queue.push(temp->right);
                curr.push_back(temp->val);

            }
            vec.push_back(curr.back());
            
        }
        return vec;
    }
};