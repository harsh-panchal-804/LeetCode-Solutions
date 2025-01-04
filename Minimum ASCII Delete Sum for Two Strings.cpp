class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=0;
        for(int i=1;i<m+1;i++){
            dp[i][0]=dp[i-1][0]+(int)s[i-1];
        }
        for(int i=1;i<n+1;i++){
            dp[0][i]=dp[0][i-1]+(int)t[i-1];
        }
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int op1=(int)s[i-1] +dp[i-1][j];
                    int op2=(int)t[j-1]+dp[i][j-1];
                    dp[i][j]=min(op1,op2);
                }
            }
        }
        return dp[m][n];

        
        
    }
};