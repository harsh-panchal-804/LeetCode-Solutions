class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1)return s;
        vector<vector<int>> dp(n,vector<int>(n));
        int len=-1;
        int p=0;
        int q=0;
        for(int i=0;i<n;i++)dp[i][i]=1;
        for(int l=1;l<s.size();l++){
            for(int i=0;i<n-l;i++){
                int j=i+l;
                if(s[i]==s[j]&& dp[i+1][j-1]==j-i-1){
                    dp[i][j]=dp[i+1][j-1]+2;
                    if(dp[i][j]>len){
                        len=dp[i][j];
                        p=i;
                        q=j;
                    }
                }
                else{
                    dp[i][j]=0;
                }

            }
        }
        
        return s.substr(p,q-p+1);
       
        
    }
};