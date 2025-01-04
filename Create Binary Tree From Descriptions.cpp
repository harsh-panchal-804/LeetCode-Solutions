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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int,int> parent;
        unordered_map<int,TreeNode*> map;
        for(auto i : desc){
            parent[i[1]]=i[0];
        }
        int par;
        for(auto i : desc){
            if(!parent.count(i[0])){
                par=i[0];
            }
        }
        for(auto pai: desc){
           if(!map[pai[0]]){
                TreeNode* root=new TreeNode(pai[0]);
                map[pai[0]]=root;
           }
           if(!map[pai[1]]){
                TreeNode* child=new TreeNode(pai[1]);
                map[pai[1]]=child;
           }
        }
        for(auto i : desc){
            if(i[2]==1){
                map[i[0]]->left=map[i[1]];
            }
            else{
                map[i[0]]->right=map[i[1]];
            }
        }
        return map[par];

        
    }
};