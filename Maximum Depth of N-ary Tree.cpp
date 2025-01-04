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
    int maxDepth(Node* root) {
        int count=0;
        queue<Node*>queue;
        if(!root) return 0;
        queue.push(root);
        while(!queue.empty()){
            int s=queue.size();
            for(int i=0;i<s;i++){
                Node*temp=queue.front();
                queue.pop();
                for(auto i : temp->children)queue.push(i);
            }
            count++;
        }
        return count;
        
    }
};