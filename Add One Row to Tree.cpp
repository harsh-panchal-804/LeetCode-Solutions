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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        queue<TreeNode*>queue;
        if(!root)return NULL;
        int level=1;
        queue.push(root);
        while(!queue.empty()){
            int s=queue.size();
            for(int i=0;i<s;i++){
            TreeNode* temp=queue.front();
            queue.pop();
            if(level==depth-1){
                TreeNode* tl=temp->left;
                TreeNode* tr=temp->right;
                temp->left=new TreeNode(val);
                temp->right=new TreeNode(val);
                temp->left->left=tl;
                temp->right->right=tr;
                
            }
            else{
                if(temp->left)queue.push(temp->left);
                if(temp->right)queue.push(temp->right);
                
            }
            }
            level++;
            
            
        }
        return root;
        
    }
};