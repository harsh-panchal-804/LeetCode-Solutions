#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        const int mod=1e9 +7;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        function<int(int ,int ,int)> dfs=[&](int x,int y ,int prev){
            if(x<0 || y<0 || x>=n || y>=m || grid[x][y]<=prev)return 0;
            // return dp[x][y];
            if(dp[x][y]!=-1)return dp[x][y];
            int ans=1;
            ans= ( ans + dfs(x+1,y,grid[x][y]))%mod;
            ans= ( ans + dfs(x-1,y,grid[x][y]))%mod;
            ans= ( ans + dfs(x,y+1,grid[x][y]))%mod;
            ans= ( ans + dfs(x,y-1,grid[x][y]))%mod;
            return dp[x][y]=ans;
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans =(ans + dfs(i,j,-1))%mod;
            }
        }
        return ans;
    }
};