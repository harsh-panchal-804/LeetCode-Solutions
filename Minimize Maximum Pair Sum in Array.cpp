class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans=INT_MIN;
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            ans=max(ans,nums[r]+nums[l]);
            l++;
            r--;
        }
        return ans;
        
    }
};
/// 2 3 3 5
// 2 3 4 4 5 6