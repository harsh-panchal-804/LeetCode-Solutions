class Solution {
public:
    const long BASE = 29, MOD = 1000000007;

    int distinctEchoSubstrings(string str) {
        unordered_set<long> set;
        int n = str.size();
        vector<long> hash(n + 1, 0), pow(n + 1, 1);

       
        for (int i = 1; i <= n; i++) {
            hash[i] = (hash[i - 1] * BASE + str[i - 1]) % MOD;
            pow[i] = pow[i - 1] * BASE % MOD;
        }

        // Iterate through all substrings of even length
        for (int i = 0; i < n; i++) {
            for (int len = 2; i + len <= n; len += 2) {
                int mid = i + len / 2;
                long hash1 = getHash(i, mid, hash, pow);
                long hash2 = getHash(mid, i + len, hash, pow);

                if (hash1 == hash2) set.insert(hash1);
            }
        }
        return set.size();
    }

private:
    long getHash(int l, int r, vector<long>& hash, vector<long>& pow) {
        return (hash[r] - hash[l] * pow[r - l] % MOD + MOD) % MOD;
    }
};
