class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=0;
        multiset<int> set;
        int left=0;
        for(int r=0;r<nums.size();r++){
            set.insert(nums[r]);
            if(*prev(set.end())-*set.begin()>limit){
                
                set.erase(set.find(nums[left]));
                left++;
            }
            ans=max(ans,r-left+1);
        }
        return ans;
        
    }
};