class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int index, int isSwapped, vector<vector<int>>& memo) {
        // Base case: if index is out of bounds, no more swaps needed
        if (index >= nums1.size()) return 0;

        // If the result is already computed, return it
        if (memo[index][isSwapped] != -1) return memo[index][isSwapped];

        // Initialize the minimum number of swaps needed as a large number
        int minSwaps = INT_MAX;

        // Get the previous elements of nums1 and nums2
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        // If the previous elements are needed to swap, swap them for comparison
        if (isSwapped) swap(prev1, prev2);

        // Case 1: No swap at current index
        if (nums1[index] > prev1 && nums2[index] > prev2) {
            minSwaps = solve(nums1, nums2, index + 1, 0, memo);
        }

        // Case 2: if you swap the current index - i.e. swap(nums1[index], nums2[index])
        // then the current condition will become         
        if (nums2[index] > prev1 && nums1[index] > prev2) {
            minSwaps = min(minSwaps, 1 + solve(nums1, nums2, index + 1, 1, memo));
        }

        // Store the result in the memoization table and return it
        return memo[index][isSwapped] = minSwaps;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // Insert dummy elements at the beginning to simplify indexing
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // Initialize memoization table with -1
        vector<vector<int>> memo(nums1.size(), vector<int>(2, -1));

        // Start solving from the first actual element, with no swaps initially
        return solve(nums1, nums2, 1, 0, memo);
    }
};