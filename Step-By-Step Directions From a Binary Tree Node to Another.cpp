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
    TreeNode* lca(TreeNode* root,int x ,int y){
        if(!root || root-> val==x|| root->val==y){
            return root;
        }
        TreeNode* left=lca(root->left,x,y);
        TreeNode* right=lca(root->right,x,y);
        if(!left)return right;
        if(!right)return left;
        return root;
    }
    bool dfs(TreeNode* root,int value,string & path){
        if(!root){
            return false;
        }
        if(root->val==value){
            return true;
        }
        path.push_back('L');
        if(dfs(root->left,value,path)){
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if(dfs(root->right,value,path)){
            return true;
        }
        path.pop_back();
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
       TreeNode* lc=lca(root,startValue,destValue);
       string a="";
       string b="";
       dfs(lc,startValue,a);
       dfs(lc,destValue,b);

       string ans(a.size(),'U');
       for(auto i : b){
            ans.push_back(i);
       }
       return ans;
    }
};