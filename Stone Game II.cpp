class Solution {
public:
    int dp[101][1000][2] = {0};
    int dfs(int s, int m, int alice, vector<int>& piles) {
        if(s >= piles.size()) return 0;
        if(dp[s][m][alice] > 0) return dp[s][m][alice];
        int sum = alice ? 0 : INT_MAX;
        int n = piles.size();
        for(int i=1; i<=2*m; i++) {
            int temp = 0;
            for(int j=s; j<min(n, s+i); j++) {
                temp += piles[j];
            }
            if(alice) {
                sum = max(sum, temp + dfs(s+i, max(m, i), 0, piles));
            } else {
                sum = min(sum, dfs(s+i, max(m, i), 1, piles));
            }
        }
        return dp[s][m][alice] = sum;
    }
    
    int stoneGameII(vector<int>& piles) {
        return dfs(0, 1, 1, piles);
    }
};