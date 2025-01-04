class Solution {
public:
    void dfs(vector<string> &fans,string ans,int i,unordered_map<char,string> &map,string &digits){
        if(ans.size()==digits.size()){
            fans.push_back(ans);
            return;
        }
        for(auto c: map[digits[i]]){
            dfs(fans,ans+c,i+1,map,digits);
        }

    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> map;
        map['2']="abc";
        map['3']="def";
        map['4']="ghi";
        map['5']="jkl";
        map['6']="mno";
        map['7']="pqrs";
        map['8']="tuv";
        map['9']="wxyz";
        vector<string> fans;
        string ans="";
        if(digits.size()>0){
            dfs(fans,ans,0,map,digits);
        }
        return fans;
        
    }
};