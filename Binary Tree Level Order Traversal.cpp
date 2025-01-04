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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        queue<TreeNode*> queue;
        if(root==NULL) return vec;
        queue.push(root);
        while(!queue.empty()){
            vector<int> curr;
            int s=queue.size();/// if size is put in for loop it will give error as we pop elements and its size changes dynamically
            for(int i=0;i<s;i++){
                TreeNode* temp=queue.front();
                queue.pop();
                curr.push_back(temp->val);
                if(temp->left) queue.push(temp->left);
                if(temp->right) queue.push(temp->right);
                
            }
            vec.push_back(curr);
            
        }
        return vec;
        
    }
};