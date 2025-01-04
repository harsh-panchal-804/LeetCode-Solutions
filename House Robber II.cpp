class Solution {
public:
    int solve(vector<int>&nums){
    
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int> dp(n+1);
        dp[n]=0;
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i]=max(dp[i+1],dp[i+2]+nums[i]);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int> first(next(nums.begin()),nums.end());
        vector<int> sec(nums.begin(),prev(nums.end()));
        return max(solve(first),solve(sec));
        
    }
};