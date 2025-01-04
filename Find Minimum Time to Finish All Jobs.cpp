class Solution {
public:
    int dp[13][1 << 12];

    vector<int> precomputeSums(const vector<int>& jobs, int n) {
        vector<int> subsetSums(1 << n, 0);
        for (int mask = 0; mask < (1 << n); ++mask) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)) sum += jobs[j];
            }
            subsetSums[mask] = sum;
        }
        return subsetSums;
    }

    int solve(int i, int mask, vector<int>& jobs, int n, int k, const vector<int>& subsetSums) {
        if (i >= k) return (mask == (1 << n) - 1) ? 0 : 1e8;
        if (dp[i][mask] != -1) return dp[i][mask];
        
        int ans = 1e8;
        for (int submask = mask ^ ((1 << n) - 1); submask; submask = (submask - 1) & (mask ^ ((1 << n) - 1))) {
            int currentSum = subsetSums[submask];
            ans = min(ans, max(currentSum, solve(i + 1, mask | submask, jobs, n, k, subsetSums)));
        }

        return dp[i][mask] = ans;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        memset(dp, -1, sizeof(dp));
        
        vector<int> subsetSums = precomputeSums(jobs, n);
        
        return solve(0, 0, jobs, n, k, subsetSums);
    }
};
