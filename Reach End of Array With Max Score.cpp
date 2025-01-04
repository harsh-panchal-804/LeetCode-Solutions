class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        int l=nums[0];
        int j=0;
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[j]){
                ans+=(l*1ll*(i-j));
                l=nums[i];
                j=i;
            }
        }
        ans+=(l*1ll*(n-1-j));
        return ans;
    }
};