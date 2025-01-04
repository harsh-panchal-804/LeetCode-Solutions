class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<n+1;i++){
            dp[0][i]=0;
        }
        for(int j=1;j<n+1;j++){
            dp[1][j]=grid[0][j-1]+dp[1][j-1];
        }
        for(int i=1;i<m+1;i++){
            dp[i][1]=grid[i-1][0]+dp[i-1][1];
        }
        for(int i=2;i<m+1;i++){
            for(int j=2;j<n+1;j++){
                dp[i][j]=grid[i-1][j-1]+min(dp[i-1][j],dp[i][j-1]);
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        return dp[m][n];
        
    }
};