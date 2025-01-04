class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                int end=i;
                int start=stk.top()+1;
                reverse(s.begin()+start,s.begin()+end);
                stk.pop();
            }
            else if(s[i]=='('){
                stk.push(i);
            }
        }
        string ans="";
        for(auto &e : s){
            if(e!=')' && e!='('){
                ans+=e;
            }
        }
        return ans;



    }
};
//// 1 2 7 9 