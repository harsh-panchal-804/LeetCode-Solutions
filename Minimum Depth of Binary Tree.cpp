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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> queue;
        if(!root) return 0;
        int lvl=1;
        queue.push(root);
        while(!queue.empty()){
            int s=queue.size();
            for(int i=0;i<s;i++){
                TreeNode*temp=queue.front();
                queue.pop();
                if(!temp->left&& !temp->right)return lvl;
                if(temp->left)queue.push(temp->left);
                if(temp->right)queue.push(temp->right);
            }
            lvl++;
            
        } 
        return lvl;

        
    }
};