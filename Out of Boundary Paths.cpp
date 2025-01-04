class Solution {
public:
    int mod=1e9+7;
    int dp[51][51][51];
    vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
    int solve(int m,int n,int moves,int row,int col){
        if(row<0||col<0 || row>=m || col>=n)return 1;
        if(moves==0)return 0;
        if(dp[row][col][moves]!=-1)return dp[row][col][moves];
        int ans=0;
        for(auto & dir:dirs){
            int dx=dir.first;
            int dy=dir.second;
            ans=(ans+solve(m,n,moves-1,row+dx,col+dy))%mod;
        }
        return dp[row][col][moves]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,maxMove,startRow,startColumn);
    }
};