class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ones=0;
        int zeroes=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                string str=s.substr(i,j-i+1);
                ones=count(str.begin(),str.end(),'1');
                zeroes=count(str.begin(),str.end(),'0');
                if(ones<=k || zeroes<=k)ans++;
            }
        }
        return ans;
        
    }
};