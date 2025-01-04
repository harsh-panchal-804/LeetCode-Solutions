class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long int count=0;
        int l=0;
        int currmin=-2;
        int currmax=-2;
        for(int r=0;r<nums.size();r++){
            if(nums[r]>maxK|| nums[r]<minK){
                l=r+1;
                continue;
            }
            if(nums[r]==maxK) currmax=r;
            if(nums[r]==minK) currmin=r;
            count+=max(min(currmax,currmin)-l+1,0);///r-l+1 we put x as l can be greater than r
            
        }
        return count;
        
    }
};