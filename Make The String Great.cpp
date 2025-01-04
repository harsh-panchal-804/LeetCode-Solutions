class Solution {
public:
    string makeGood(string s) {
        stack<char> stack;
        for(auto i : s){
            if(!stack.empty()&& abs(i-stack.top())==32){
                stack.pop();
            }
            else stack.push(i);
        }
        string ans="";
        while(!stack.empty()){
            ans=stack.top()+ans;
            stack.pop();
        }
        return ans;
        
    }
};