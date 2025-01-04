class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                string a=s.substr(i,j-i+1);
                reverse(a.begin(),a.end());
                if(s.substr(i,j-i+1)==a) count++;
            }
        }
        return count;

        
    }
};