class Solution {
public:
  
    void generateSums(const vector<int>& nums, int start, int end, long long current, vector<long long>& sums) {
        if (start == end) {
            sums.push_back(current);
            return;
        }
        generateSums(nums, start + 1, end, current, sums);
        generateSums(nums, start + 1, end, current + nums[start], sums);
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int mid = n / 2;
        
        vector<long long> sums1, sums2;
        generateSums(nums, 0, mid, 0, sums1);
        generateSums(nums, mid, n, 0, sums2);
        
        sort(sums2.begin(), sums2.end());
        int ans = abs(goal);
        
        for (long long s : sums1) {
            long long target = goal - s;
            auto it = lower_bound(sums2.begin(), sums2.end(), target);
            if (it != sums2.end()) {
                ans = min(ans, (int)abs(s + *it - goal));
            }
            if (it != sums2.begin()) {
                it--;
                ans = min(ans, (int)abs(s + *it - goal));
            }
        }
        return ans;
    }
};
