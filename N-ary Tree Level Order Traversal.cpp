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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*>queue;
        if(!root)return ans;
        queue.push(root);
        while(!queue.empty()){
            int s=queue.size();
            vector<int>curr;
            for(int i=0;i<s;i++){
                Node* temp=queue.front();
                queue.pop();
                for(auto i :temp->children)queue.push(i);
                curr.push_back(temp->val);
            }
            ans.push_back(curr);
        }
        return ans;
        
    }
};