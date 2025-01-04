class Solution {
public:
    int dp[100001][2][3];
    int solve(int i,int own,int k,vector<int>&prices){
        if(i>=prices.size())return 0;
        if(k<=0)return 0;
        if(dp[i][own][k]!=-1)return dp[i][own][k];
        if(own){
            ///you can sell or not
            int op1=solve(i+1,1,k,prices);
            int op2=prices[i]+solve(i+1,0,k-1,prices);
            return dp[i][own][k]=max(op1,op2);
        }
        else{
            /// u can buy or  not
            int op1= solve(i+1,0,k,prices);
            int op2=-prices[i]+solve(i+1,1,k,prices);
            return dp[i][own][k]=max(op1,op2);
        }
    }
    int maxProfit(vector<int>& prices) {
        ///dp[i][own][k]
        ///sell-> 1 trans
        int k=2;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,2,prices);
       
        
    }
};