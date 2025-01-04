class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort (nums.begin(), nums.end());
        int ans = 0, prediff = INT_MAX;
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs (target - sum);
                if (diff < prediff) {
                    ans = sum;
                    prediff = diff;
                }
                if (target > sum)
                    left++;
                else
                    right--;    
            }
        }
        return ans;
    }
};