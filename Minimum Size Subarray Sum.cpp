class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int sum=0;
        int ans=INT_MAX;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while(sum>=target){
                ans=min(ans,r-left+1);
                sum-=nums[left];
                left++;
            }
        }
        if(ans==INT_MAX) return 0;
        else return ans;
        
    }
};