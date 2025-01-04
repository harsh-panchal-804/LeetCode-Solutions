class Solution {
public:
    int mod=1e9+7;
    int dp[501][501];
    int solve(int steps,int len,int curr,int static_step){
        if(curr>static_step)return 0;
        if(curr<0 || curr>=len)return 0;
        if(steps==0){
            if(curr==0)return 1;
            return 0;
        }
        if(dp[steps][curr]!=-1)return dp[steps][curr];
        int ans=0;
        ans=(ans+solve(steps-1,len,curr+1,static_step))%mod;
        ans=(ans+solve(steps-1,len,curr-1,static_step))%mod;
        ans=(ans+solve(steps-1,len,curr,static_step))%mod;
        return dp[steps][curr]=ans;
    }
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        return solve(steps,arrLen,0,steps);   
    }
};