#pragma GCC target("avx2")
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l=k;
        int r=k;
        int ans=-1;
        int n=nums.size();
        int curr_min=INT_MAX;
        while(l>=0  && r < n){
            curr_min=min({curr_min,nums[l],nums[r]});
            ans =max(ans, (r-l+1) * curr_min);
            int op1=(r+1<n)? (r-l+1+1) *(min(curr_min,nums[r+1])) :INT_MIN;
            int op2=(l-1>=0) ? (r-l+2) *(min(curr_min,nums[l-1])) :INT_MIN;
            if(op1>op2){
                r++;
            }
            else{
                l--;
            }
        }
        return ans;
    }
};