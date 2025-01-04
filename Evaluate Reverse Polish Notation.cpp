class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for(auto str: tokens){
            if(str.size()>1 || isdigit(str[0])){
                stack.push(stoi(str));
            }
            else{
                int op2=stack.top();
                stack.pop();
                int op1=stack.top();
                stack.pop();
                switch (str[0]) {
                    case '+': 
                        stack.push(op1 + op2);
                        break;
                    case '-': 
                        stack.push(op1 - op2);
                        break;
                    case '*': 
                        stack.push(op1 * op2);
                        break;
                    case '/': 
                        stack.push(op1 / op2);
                        break;
                }
                
            }
        }
        
    return stack.top();
        
    }
};