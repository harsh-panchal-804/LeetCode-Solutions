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
    vector<long long int> vec;

    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root)return 0;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            int s=queue.size();
            long long int sum=0;
            for(int i=0;i<s;i++){
                TreeNode* temp=queue.front();
                queue.pop();
                sum+=temp->val;
                if(temp->left)queue.push(temp->left);
                if(temp->right)queue.push(temp->right);
            }
            vec.push_back(sum);
           
        }
        priority_queue<long long int> pr;
        for(auto i : vec) pr.push(i);
        if(pr.size()<k)return -1;
        k--;
        while(k!=0){
            pr.pop();
            k--;
        }
        return pr.top();
        
    }
};