class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long int ans=-1;
        long long int prefix=0;
        sort(nums.begin(),nums.end());
        for(auto i : nums){
            if(prefix>i){
                ans=prefix+i;
            }
            prefix+=i;
        }
        return ans;
        
    }
};