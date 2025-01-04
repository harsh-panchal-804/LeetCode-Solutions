class Solution {
public:
    string stringHash(string s, int k) {
        string ans="";
        int n=s.size();
        int i=0;
        while(i<n){
            int hashed_char=0;
            for(int j=0;j<k;j++){
                hashed_char+=(s[i]-'a');
                i+=1;
            }
            ans.push_back((hashed_char%26)+'a');
        }
        return ans;
        
    }
};