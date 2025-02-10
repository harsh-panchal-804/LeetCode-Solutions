class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 1, up = 0, down = 0;
        for (int i = 0; i < s.size(); ++i) {
            down += s[i] == 'N' ? 1 : s[i] == 'S' ?-1 :0;
            up += s[i]=='W'?1: s[i] == 'E' ? -1 : 0;
            ans = max(ans, min(abs(up) + abs(down) + 2 * k, i + 1));
        }
        return ans;
    }
};