class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int>& nums1, vector<int>& nums2,int i,int j){
        if(i>=nums1.size()|| j>=nums2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(nums1[i]==nums2[j]){
            ans=1+solve(nums1,nums2,i+1,j+1); 
        }
        solve(nums1,nums2,i+1,j);
        solve(nums1,nums2,i,j+1);
        return dp[i][j]=ans;

    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        int maxlen=0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                maxlen = max(maxlen, solve(nums1, nums2, i, j));
            }
        }
        return maxlen;
    }
};