class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<int> degree(n,0);
        for(auto i : roads){
            int x=i[0];
            int y=i[1];
            dp[x][y]=1;
            dp[y][x]=1;
            degree[x]++;
            degree[y]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp=degree[i]+degree[j]-(dp[i][j]==1);
                ans=max(ans,temp);
            }
        }
        return ans;


        
    }
};