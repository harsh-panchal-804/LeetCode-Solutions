class Solution {
public:
    int minLength(string s) {
        
        stack<char>st;
        int n=s.size();
        for(char c:s)
        {
            if(!st.empty() && ( (c=='B' && st.top()=='A') || (c=='D' && st.top()=='C')))
            {
                st.pop();
            }else{
                st.push(c);
            }
        }
        return st.size();
    }
};