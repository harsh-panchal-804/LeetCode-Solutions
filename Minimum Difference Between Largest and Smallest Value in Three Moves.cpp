class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4)return 0;
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        ans=min(ans,nums[n-1]-nums[3]);
        ans=min(ans,nums[n-4]-nums[0]);
        ans=min(ans,nums[n-3]-nums[1]);
        ans=min(ans,nums[n-2]-nums[2]);
        return ans;

        
        /// 0 1 5 6 7 8 9 10 14
    }
};