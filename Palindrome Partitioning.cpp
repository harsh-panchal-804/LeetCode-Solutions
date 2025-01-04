class Solution {
public:
bool valid(string s){
            int n = s.size();
            for(int i=0; i<n/2; i++){
                if(s[i] != s[n-i-1])
                    return false;
        }
        return true;
    }
    void dfs(string &s ,int i,vector<string> &ans,vector<vector<string>> &fans){
        if(i>=s.length()){
            fans.push_back(ans);
            return;
        }
        
        for(int j=i;j<s.length();j++){
            string sub=s.substr(i,j-i+1);
            if(valid(sub))
            {
                ans.push_back(sub);
                dfs(s,j+1,ans,fans);
                ans.pop_back();
            }
            
        }
        
        
        
    }
    vector<vector<string>> partition(string s) {
        vector<string> ans;
        vector<vector<string>> fans;
        string str="";
        dfs(s,0,ans,fans);
        return fans;
        
    }
};