class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int sw) {
        int n=books.size();
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=books[0][1];
        for(int i=1;i<n+1;i++){
            int rsw=sw-books[i - 1][0];
            int mxht=books[i - 1][1];
            dp[i]=dp[i - 1]+mxht;
            int j=i-1;
            while (j > 0 && rsw - books[j - 1][0] >= 0) {
                rsw -= books[j - 1][0];
                mxht = max(mxht, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + mxht);
                j--;
            }
        }

        return dp[n];
        
    }
};