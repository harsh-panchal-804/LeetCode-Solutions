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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)return {};
        vector<double> vec;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            long long s=queue.size();
            double sum=0;
            for(int i=0;i<s;i++){
                TreeNode* temp=queue.front();
                queue.pop();
                sum+=temp->val;
                if(temp->left)queue.push(temp->left);
                if(temp->right)queue.push(temp->right);
            }
            vec.push_back(sum/s);
        }
        return vec;
        
    }
};