class Solution {
public:
    void dfs(vector<string> &fans,string ans,int i,string &s){
        if(i==s.size()){
            fans.push_back(ans);
            return;
        }
        if(isalpha(s[i])){
            ans+=toupper(s[i]);
            dfs(fans,ans,i+1,s);
            ans.pop_back();
            ans+=tolower(s[i]);
            dfs(fans,ans,i+1,s);
        }
        else{
            ans.push_back(s[i]);
            dfs(fans,ans,i+1,s);
        }

    }
    vector<string> letterCasePermutation(string s) {
        string ans="";
        vector<string> fans;
        dfs(fans,ans,0,s);
        return fans;
        
    }
};