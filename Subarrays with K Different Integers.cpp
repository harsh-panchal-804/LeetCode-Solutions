class Solution {
public:
    int helper(vector<int>&nums,int k){
        int ans=0;
        int l=0;
        unordered_map<int,int> map;
        for(int r=0;r<nums.size();r++){
            map[nums[r]]++;
            while(l<=r&& map.size()>k){
                map[nums[l]]--;
                if(map[nums[l]]==0) map.erase(nums[l]);
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
        
    }
};