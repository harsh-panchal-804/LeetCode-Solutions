class Solution {
public:
    int dp[1000+10][2][500+50];
    int solve(vector<int>&prices,int i,int own,int k){
        if(i>=prices.size())return 0;
        if(dp[i][own][k]!=-1)return dp[i][own][k];
        if(own){
            //sell or not
            int op1=prices[i]+solve(prices,i+1,0,k);
            int op2=solve(prices,i+1,1,k);
            return dp[i][own][k]= max(op1,op2);
        }
        else{
            //buy or not
            int op1=k>0?-prices[i]+solve(prices,i+1,1,k-1):INT_MIN;
            int op2=solve(prices,i+1,0,k);
            return dp[i][own][k]= max(op1,op2);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,0,k);
    }
};