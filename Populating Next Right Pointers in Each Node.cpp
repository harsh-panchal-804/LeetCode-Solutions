/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root){
        queue<Node*>queue;
        if(!root) return NULL;
        queue.push(root);
        while(!queue.empty()){
            int s=queue.size();
            vector<Node*>vec;
            cout<<endl;
            for(int i=0;i<s;i++){
                Node*temp=queue.front();
                queue.pop();
                vec.push_back(temp);
                if(temp->left)queue.push(temp->left);
                if(temp->right)queue.push(temp->right);
            }
            for(auto i : vec)cout<<i->val<<"->";
            cout<<"lvl over";
            vec.back()->next=NULL;
            if(vec.size()>=2){
                for(int i=vec.size()-2;i>=0;i--){
                vec[i]->next=vec[i+1];
            }
            }
            
            
            

        }
        return root;
        
    }
};