class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,int curr,vector<vector<int>>& grid,int m ,int n){
        if(j==n-1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int op1=i-1>=0 && j+1<n && grid[i-1][j+1]>curr?1+solve(i-1,j+1,grid[i-1][j+1],grid,m,n):0;
        int op2=j+1<n && grid[i][j+1]>curr? 1+solve(i,j+1,grid[i][j+1],grid,m,n):0;
        int op3=i+1<m && j+1<n && grid[i+1][j+1]>curr? 1+solve(i+1,j+1,grid[i+1][j+1],grid,m,n):0;
        return dp[i][j]=max({op1,op2,op3});

    }
    int maxMoves(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            ans=max(ans,solve(i,0,grid[i][0],grid,m,n));
        }
        return ans;
        
    }
};