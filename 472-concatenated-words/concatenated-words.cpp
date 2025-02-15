class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> set(words.begin(), words.end());
        for (auto& word : words) {
            int n = word.size();
            if (n == 0) continue;
            set.erase(word);  
            vector<bool> dp(n + 1, false);
            dp[0] = true; 
            for (int i = 0; i < n; i++) {
                if (!dp[i]) continue;
                for (int j = i + 1; j <= n; j++) {
                    if (j - i < n && set.count(word.substr(i, j - i))) {
                        dp[j] = true;
                    }
                }
            }
            if (dp[n]) ans.push_back(word);
            set.insert(word);
        }
        return ans;
    }
};
