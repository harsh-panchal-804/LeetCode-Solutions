class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>& dungeon,int i,int j,int m,int n){
        if(i==m-1 && j==n-1){
            return max(1,1-dungeon[i][j]);
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int op1=j<n-1?solve(dungeon,i,j+1,m,n)-dungeon[i][j]:1e8;
        int op2=i<m-1?solve(dungeon,i+1,j,m,n)-dungeon[i][j]:1e8;
        return dp[i][j]= max(1,min(op1,op2));

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        /// maximise
        //// max(min)
        memset(dp,-1,sizeof(dp));
        return solve(dungeon,0,0,dungeon.size(),dungeon[0].size());
    }
};