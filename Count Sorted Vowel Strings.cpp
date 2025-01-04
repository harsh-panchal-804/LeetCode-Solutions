class Solution {
public:
    int countVowelStrings(int n) {
        function<int(int, int)> dfs = [&](int index, int digits) {
            if (digits == n) return 1;
            int count = 0;
            for (int i = index; i < 5; i++) {
                count += dfs(i, digits + 1);
            }
            return count;
        };
        return dfs(0, 0);
    }
};
