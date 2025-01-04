class Solution {
public:
    void dfs(int i,string &s , vector<string>&wordDict,vector<string>&ans,vector<string>&fans){
        if(i>=s.size()){
            string temp="";
            for(auto i : ans){
                temp+=i;
                temp+=" ";
            }
            temp.pop_back();
            fans.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++){
            for(auto w:wordDict){
                if(w==s.substr(i,j-i+1)){
                    ans.push_back(w);
                    dfs(j+1,s,wordDict,ans,fans);
                    ans.pop_back();
                }  
            }
           
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        vector<string> fans;
        dfs(0,s,wordDict,ans,fans);
        return fans;
    }
};