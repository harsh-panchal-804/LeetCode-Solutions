class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int ans=INT_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[l]<nums[r]){
                ans=min(ans,nums[l]);
            }
            ans=min(ans,nums[mid]);
            if(nums[l]<=nums[mid]) l=mid+1;
            else r=mid-1;
        }
        return ans;
        
    }
};