class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> prevdp(grid[0].begin(),grid[0].end());
        for(int r=1;r<n;r++){
            vector<int> dp(n,INT_MAX);
            for(int c=0;c<n;c++){
                for(int col=0;col<n;col++){
                    if(col!=c){
                        dp[c]=min(dp[c],prevdp[col]+grid[r][c]);
                    }
                }
            }
            prevdp=dp;
        }
        return *min_element(prevdp.begin(),prevdp.end());
        
    }
};