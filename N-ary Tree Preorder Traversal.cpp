/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> vec;
    void dfs(Node* root){
        if(root){
            vec.push_back(root->val);
            for(auto i : root->children){
                dfs(i);
            }
        }
    }
    vector<int> preorder(Node* root) {
        dfs(root);
        return vec;
        
    }
};