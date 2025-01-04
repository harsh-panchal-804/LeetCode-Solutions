class Solution {
public:
    int minimumLength(string s) {
        int ans=s.size();
        int l=0;
        int r=s.size()-1;
        int n=s.size()-1;
        unordered_set<char> prefix;
        //prefix.insert(s[0]);
        unordered_set<char> suffix;
        ///suffix.insert(s[n-1]);
        while(l<r && s[l]==s[r]){
            char ch=s[l];
            while(l <r && s[l]==ch){
                l++;
            }
            while(r>=l && s[r]==ch){
                r--;
            }
        }
        return r-l+1;
        
    }
};