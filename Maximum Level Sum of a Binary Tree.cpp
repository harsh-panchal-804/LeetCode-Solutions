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
    int level=0;
    int maxsum=INT_MIN;
    unordered_map<int,int>map;

    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>queue;
        if(!root)return 0;
        queue.push(root);
        while(!queue.empty()){
            level++;
            int s=queue.size();
            int lvlsum=0;
            for(int i=0;i<s;i++){
                TreeNode* temp=queue.front();
                queue.pop();
                lvlsum+=temp->val;
                if(temp->left)queue.push(temp->left);
                if(temp->right)queue.push(temp->right);
            }
            map[level]=lvlsum;
            maxsum=max(maxsum,lvlsum);

        }
        int ans=INT_MAX;
        for(auto i : map){
            if(i.second==maxsum){
                ans=min(ans,i.first);
            }
        }
        return ans;
        
    }
};