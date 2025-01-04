class Solution {
public:
    int numSquares(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        vector<int> coins;
        for(int i=1;i*i<=n;i++){
            coins.push_back(i*i);
        }
        vector<int> dp(n+1,1e9);
        dp[0]=0;
        for(int i=0;i<n+1;i++){
            for(auto j : coins){
                if(i>=j){
                    dp[i]=min(dp[i],dp[i-j]+1);
                }
            }
        }
        return dp[n];
        
    }
};