class Solution {
public:
    int dp[5005][16][7];
    int mod=1e9+7;
    int solve(int n,vector<int>&rolls,int freq,int last){
        if(n==0){
            return 1;
        }
        if(dp[n][freq][last]!=-1)return dp[n][freq][last];
        int ans=0;
        for(int i=1;i<=6;i++){
            if(i==last&& freq>=rolls[i-1]){
                continue;
            }
            if(i==last){
                ans=(ans+solve(n-1,rolls,freq+1,i))%mod;
            }
            else{
                ans=(ans+solve(n-1,rolls,1,i))%mod;
            }
        }
        return dp[n][freq][last]=ans;
        
    }
    int dieSimulator(int n, vector<int>& rolls) {
        memset(dp,-1,sizeof(dp));
        int count=0;
        for(int i=1;i<=6;i++){
            count=(count+solve(n-1,rolls,1,i))%mod;
        }
        return count;
    }
};