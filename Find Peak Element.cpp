class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        if(nums.size()==1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[r]>nums[r-1]) return r;

        while(l<=r){
            int mid=(l+r)/2;
            // search for monotonically inc or dec sub array and then return its endpoints
            if(mid<nums.size()-1 && nums[mid]<nums[mid+1]){
                l=mid+1;
            }
            else if(mid>0 && nums[mid]<nums[mid-1]){
                r=mid-1;
            }
            else return mid;
        }
        return -1;
        
    }
};
///3 2 1 