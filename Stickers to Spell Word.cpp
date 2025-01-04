class Solution {
public:
    int solve(vector<int>& dp, vector<vector<int>>& stickerCounts, string& target, int mask) {
        if (mask == ((1 << target.size()) - 1)) return 0;
        if (dp[mask] != -1) return dp[mask];

        int minStickers = 1e8;
        for (auto sticker : stickerCounts) {
            int newMask = mask;
            for (int j = 0; j < target.size(); ++j) {
                if (!(newMask & (1 << j)) && sticker[target[j] - 'a'] > 0) {
                    sticker[target[j] - 'a']--;
                    newMask |= (1 << j);
                }
            }
            if (newMask != mask) { 
                minStickers = min(minStickers, 1 + solve(dp, stickerCounts, target, newMask));
            }
        }

        return dp[mask] = minStickers;
    }

    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<vector<int>> stickerCounts(n, vector<int>(26, 0));

        
        for (int i = 0; i < n; ++i) {
            for (char ch : stickers[i]) {
                stickerCounts[i][ch - 'a']++;
            }
        }

        vector<int> dp(1 << target.size(), -1);
       
        int result = solve(dp, stickerCounts, target, 0);
        return result >=1e8 ? -1 : result;
    }
};
