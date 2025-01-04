class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++) {
            int j=(i+k)%n;
            ans.push_back(s[j]);
        }
        return ans;
    }
};