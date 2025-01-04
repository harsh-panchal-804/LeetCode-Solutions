class Solution {
public:
    string customSortString(string order, string s) {
        int count=0;
        string ans="";
        vector<int> vec(26,0);
        for(char ch: s) vec[ch-'a']++;
        for(char ch: order){
            for(int i=0;i<vec[ch-'a'];i++){
                ans+=ch;
            }
            vec[ch-'a']=0;
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<vec[i];j++){
                ans+=(i+'a');
            }
        }
        return ans;
        
        
        
    }
};