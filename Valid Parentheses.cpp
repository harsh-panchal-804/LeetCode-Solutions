class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(auto c: s){
            if(c=='[' || c=='(' || c=='{'){
                stack.push(c);
            }
            else if(stack.empty() && (c==')' || c==']' || c=='}')) return false;
            else{
                if(stack.top()=='(' && c==')') stack.pop();
                else if(stack.top()=='[' && c==']') stack.pop();
                else if(stack.top()=='{' && c=='}') stack.pop();
                else return false;
                
            }
        }
        if(!stack.empty()) return false;
        return true;
        
    }
};