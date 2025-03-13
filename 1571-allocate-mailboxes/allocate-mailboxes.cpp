class Solution {
public:
    int n;
    vector<vector<int>> costMat;      
    vector<vector<int>> memo;        
    void precomputeCost(vector<int>& houses) {
        n = houses.size();
        costMat.assign(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int mid = (i + j) / 2;
                int total = 0;
                for (int t = i; t <= j; t++) {
                    total += abs(houses[t] - houses[mid]);
                }
                costMat[i][j] = total;
            }
        }
    }
    
    
    int dp(int i, int k, const vector<int>& houses) {
        if (i < 0) return 0;         
        if (k == 0) return 1e9;        
        if (memo[i][k] != -1) return memo[i][k];
        
       
        if (k == 1) {
            memo[i][k] = costMat[0][i];
            return memo[i][k];
        }
        
        int ans = 1e9;
        for (int j = 1; j <= i; j++) {
            ans = min(ans, dp(j - 1, k - 1, houses) + costMat[j][i]);
        }
        return memo[i][k] = ans;
    }
    
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        n = houses.size();
        precomputeCost(houses);
        memo.assign(n, vector<int>(k + 1, -1));
        return dp(n - 1, k, houses);
    }
};
