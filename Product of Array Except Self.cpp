class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int pre = 1;
        for (int i = 0; i < n; i++) {
            ans[i] *= pre;
            pre *= nums[i];
        }
        int suf = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suf;
            suf *= nums[i];
        }
        return ans;
        
    }
};

/// 1 2 6 24