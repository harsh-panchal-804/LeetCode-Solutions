class Solution {
public:
    int dp[1005];
    int solve(vector<int>&cost,int i){
        if(i>=cost.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int op1=cost[i]+solve(cost,i+1);
        int op2=cost[i]+solve(cost,i+2);
        return dp[i]=min(op1,op2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(solve(cost,0),solve(cost,1));
    }
};