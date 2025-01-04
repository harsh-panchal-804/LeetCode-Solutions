class Solution {
public:
    int solve(vector<int>& values,int l,int r,vector<vector<int>>&dp){
        if(l>=r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int ans=INT_MAX;
        for(int k=l;k<r;k++){
            int temp=solve(values,l,k,dp)+solve(values,k+1,r,dp) +values[l-1]*values[k]*values[r];
            ans=min(ans,temp);
        }
        return dp[l][r]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(values,1,values.size()-1,dp);
        
    }
};