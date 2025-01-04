class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        unordered_map<char,int> m;
        for(char c:s) m[c]++;
        if(m.size()==1) return n;
        int oddCount=0;
        for(auto i :m){
            if(i.second%2==1) oddCount++;
        }
        if(oddCount>1) return n-oddCount+1;
        else return n;
    }
};