class Solution {
public:
    long long minimumSteps(string s) {
        long long int ans=0;
        int one=0;
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                ans=ans+(n-i-1-one);
                one++;
            }
        }
        return ans;
        
    }
};