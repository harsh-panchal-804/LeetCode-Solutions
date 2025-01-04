class Solution {
public:
    int numDistinct(string s, string t) {
        /// bagg bag
        int m=s.size();
        int n=t.size();
        int dp[m][n];
        memset(dp,-1,sizeof(dp));
        function<int(int,int)> dfs=[&](int i,int j){
            if(j>=t.size())return 1;
            if(i>=s.size())return 0;
            if(dp[i][j]!=-1)return dp[i][j];
            if(s[i]==t[j]){
                
                ///take or leave
                return dp[i][j]= dfs(i+1,j+1)+dfs(i+1,j);
            }
            else{
                return dp[i][j]=dfs(i+1,j);
            }
        };
        return dfs(0,0);
        
    }
};