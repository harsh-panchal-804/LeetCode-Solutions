class Solution {
public:
    int dp[5000][2][2];
    int solve(int i,int own,int cool,vector<int>&prices){
        if(i>=prices.size())return 0;
        if(dp[i][own][cool]!=-1)return dp[i][own][cool];
        if(own){
            ///sell
            int op1=prices[i]+solve(i+1,0,1,prices);
            int op2=solve(i+1,1,0,prices);
            return dp[i][own][cool]=max(op1,op2);
        }
        else{
            int op1=solve(i+1,0,0,prices);
            int op2=cool==1?0: -prices[i]+solve(i+1,1,0,prices);
            return dp[i][own][cool]=max(op1,op2);
        }
    }
    int maxProfit(vector<int>& prices) {
        ///dp[i][own][cool]
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,prices);
        
    }
};