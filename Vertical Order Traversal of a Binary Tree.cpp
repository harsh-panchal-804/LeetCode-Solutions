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
    static bool cmp(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
        if(a.second.second!=b.second.second)return a.second.second<b.second.second;
        else if(a.second.second==b.second.second && a.second.first==b.second.first)return a.first<b.first;
        else return a.second.first<b.second.first;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {{}};
        vector<pair<int,pair<int,int>>> vec;
        queue<pair<TreeNode*,pair<int,int>>>queue;
        queue.push({root,{0,0}});
        while(!queue.empty()){
            int s=queue.size();
            for(int i=0;i<s;i++){
                int row=queue.front().second.first;
                int col=queue.front().second.second;
                TreeNode* temp=queue.front().first;
                vec.push_back({temp->val,{row,col}});
                queue.pop();
                if(temp->left)queue.push({temp->left,{row+1,col-1}});
                if(temp->right)queue.push({temp->right,{row+1,col+1}});
            }

        }
        for(auto i : vec){
            cout<<i.first<<"x,y "<<i.second.first<<" "<<i.second.second<<endl;
        }
        sort(vec.begin(),vec.end(),cmp);
        map<int,vector<int>> map;
        for(auto i : vec){
            map[i.second.second].push_back(i.first);
        }
        vector<vector<int>> ans;
        for(auto i : map){
            ans.push_back(i.second);
        }
        

        return ans;
        
    }
};