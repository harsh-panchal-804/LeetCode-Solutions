class Solution {
public:
    void dfs(int closed,int open,vector<string> &fans,string &ans,int n){
        if(open==n && closed==n){
            fans.push_back(ans);
            return;
        }
        if(open<n){
            ans+='(';
            dfs(closed,open+1,fans,ans,n);
            ans.pop_back();
        }
        if(closed<open){
            ans+=')';
            dfs(closed+1,open,fans,ans,n);
            ans.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> fans;
        string ans="";
        dfs(0,0,fans,ans,n);
        return fans;  
    }
};