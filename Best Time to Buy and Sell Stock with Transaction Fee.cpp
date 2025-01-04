class Solution {
public:
    int dp[50001][2];
    int solve(vector<int>& prices,int fee,int i,int own){
        if(i>=prices.size())return 0;
        if(dp[i][own]!=-1)return dp[i][own];
        if(own){
            int op1=prices[i]+solve(prices,fee,i+1,0);
            int op2=solve(prices,fee,i+1,1);
            return dp[i][own]=max(op1,op2);
        }
        else{///not own so u buy
            int op1=-prices[i]-fee+solve(prices,fee,i+1,1);
            int op2=solve(prices,fee,i+1,0);
            return dp[i][own]=max(op1,op2);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        //// dp[i][own] fee on buying
        memset(dp,-1,sizeof(dp));
        return solve(prices,fee,0,0);

        
    }
};