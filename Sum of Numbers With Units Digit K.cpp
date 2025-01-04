class Solution {
public:
    int coinchange(vector<int>&coins,int num){
        vector<int>dp(num+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=num;i++){
            for(auto c: coins){
                if(i>=c && dp[i-c]!=INT_MAX){
                    dp[i]=min(dp[i],dp[i-c]+1);
                }
            }
        }
        return dp[num]==INT_MAX?-1: dp[num];
    }
    int minimumNumbers(int num, int k) {
        vector<int> ans;
        for(int i=0;i<=num;i++){
            if(i%10==k)ans.push_back(i);
        }
        return coinchange(ans,num);
        
    }
};