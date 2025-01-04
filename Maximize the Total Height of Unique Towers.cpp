class Solution {
public:
    long long maximumTotalSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long cur=nums[0];
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            cur=min(cur,(long long)nums[i]);
            if( cur<1)return -1;
            ans+=cur;
            cur--;
        }
        return ans;
        
        
    }
};