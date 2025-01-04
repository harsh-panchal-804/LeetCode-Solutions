class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /// s1 - s2 is min s1 is y stones
        int m=stones.size();
        int n=accumulate(stones.begin(),stones.end(),0);
        vector<vector<bool>> dp(m+1,vector<bool>(n+1));
        for(int i=0;i<n+1;i++){
            dp[0][i]=false;
        }
        for(int i=0;i<m+1;i++){
            dp[i][0]=true;
        }
        
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(j>=stones[i-1]){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-stones[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        for(int i=n/2;i>=0;i--){
            if(dp[m][i]==true){
                return n-(2*i);
            }
        }
        return -1;
        
    }
};