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
    int widthOfBinaryTree(TreeNode* root){
        if(!root) return 0;
        queue<pair<TreeNode*,int>>queue;
        queue.push({root,0});
        int ans=0;
        while(!queue.empty()){
            int s=queue.size();
            int left=0;
            int right=0;
            int min=queue.front().second;
            cout<<"lVl "<<min;

            for(int i=0;i<s;i++){
                long curr=queue.front().second-min;
                TreeNode*temp=queue.front().first;
                if(i==0) left=curr;
                if(i==s-1)right=curr;
                queue.pop();
                if(temp->left)queue.push({temp->left,curr*2+1});
                if(temp->right)queue.push({temp->right,curr*2+2});
                
            }
            ans=max(ans,right-left+1);
            cout<<ans<<endl;
        }
        return ans;
        
        
    }
};