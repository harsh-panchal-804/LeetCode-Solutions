class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum=0;
        int maxsum=nums[0];
        int left=0;
        int right=0;
        int maxl;
        int maxr;
        for(right=0;right<nums.size();right++){
            if(cursum<0){
                cursum=0;
                left=right;
            }
            cursum+=nums[right];
            if(cursum>maxsum){
                maxsum=cursum;
                maxl=left;
                maxr=right;
            }
        }
        return maxsum;
        
        
    }
};