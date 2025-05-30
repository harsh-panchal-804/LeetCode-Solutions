class Solution {
public:
    int dp[(15)][(1<<15)];
    int dfs(int i,vector<int>& nums1,vector<int>& nums2,int mask){
        if(i>=nums1.size())return 0;
        if(dp[i][mask]!=-1)return dp[i][mask];
        int ans=INT_MAX;
        for(int j=0;j<nums2.size();j++){
            if(mask & (1<<j))continue;
            ans=min(ans,(nums1[i]^nums2[j])  + dfs(i+1,nums1,nums2,mask |(1<<j)) );
        }
        return dp[i][mask]= ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return dfs(0,nums1,nums2,0);
    }
};