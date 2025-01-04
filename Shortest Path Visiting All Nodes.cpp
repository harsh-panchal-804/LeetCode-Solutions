class Solution {
public:
    int dp[13][(1<<13)+1];
    int solve(int curr, vector<vector<int>>& vec,int mask,int n){
        if(mask==(1<<n)-1)return 0;
        if(dp[curr][mask]!=-1)return dp[curr][mask];
        int ans=1e8;
        for(int c=0;c<n;c++){
            if(mask&(1<<c))continue;
            ans=min(ans,vec[curr][c]+solve(c,vec,mask|(1<<c),n));
        }
        return dp[curr][mask]=ans;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> vec(n,vector<int>(n,1e8));
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(auto child: graph[i]){
                vec[i][child]=1;
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    vec[i][j]=min(vec[i][j],vec[i][k]+vec[k][j]);
                }
            }
        }
        int fans=1e8;
        for(int i=0;i<n;i++){
            fans=min(fans,solve(i,vec,(1<<i),n));
        }
        return fans;
    }
};