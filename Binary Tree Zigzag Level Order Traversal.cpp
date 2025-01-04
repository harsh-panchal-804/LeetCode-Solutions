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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>queue;
        vector<vector<int>> vec;
        if(root==NULL) return vec;
        queue.push(root);
        while(!queue.empty()){
            vector<int>curr;
            int s=queue.size();
            for(int i=0;i<s;i++){
                TreeNode* temp=queue.front();
                queue.pop();
                curr.push_back(temp->val);
                if(temp->left) queue.push(temp->left);
                if(temp->right)queue.push(temp->right);
            }
            vec.push_back(curr);
        }
        for(int i=0;i<vec.size();i++){
            if(i%2!=0){
                reverse(vec[i].begin(),vec[i].end());
            }
        }
        return vec;

        
    }
};