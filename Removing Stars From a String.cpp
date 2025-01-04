class Solution {
public:
    string removeStars(string s) {
        stack<char> stack;
        for(auto c: s){
            if(c=='*'){
                stack.pop();
            }
            else{
                stack.push(c);
            }
        }
        string ans="";
        while(!stack.empty()){
            ans+=stack.top();
            stack.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};