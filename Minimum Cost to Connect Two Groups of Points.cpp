class Solution {
public:
    int dp[13][13][(1<<13)];
    int solve(int curr_row,int curr_col,int mask,vector<vector<int>>& cost,int n,int m){
        if(curr_row==n){
            if(mask==(1<<m)-1)return 0;
            return 1e8;
        }
        if(curr_col>=m)return 1e8;
        if(dp[curr_row][curr_col][mask]!=-1)return dp[curr_row][curr_col][mask];
        int op1=cost[curr_row][curr_col]+solve(curr_row+1,0,mask|(1<<curr_col),cost,n,m);
        int op2=cost[curr_row][curr_col]+solve(curr_row,curr_col+1,mask|(1<<curr_col),cost,n,m);
        int op3=solve(curr_row,curr_col+1,mask,cost,n,m);
        return dp[curr_row][curr_col][mask]=min({op1,op2,op3});
    }
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n=cost.size();
        int m=cost[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,0,cost,n,m);
        return ans;
    }
};
