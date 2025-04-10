class Solution {
public:
    int ans = 0;
    int n;
    bool isSqr(int a) {
        int root = sqrt(a);
        return root * root == a;
    }
    void dfs(int node, unordered_map<int, int>& freq, unordered_map<int, vector<int>>& graph, int len) {
        if (len >= n) {
            ans++;
            return;
        }
        for (auto child : graph[node]) {
            if (freq[child] == 0) continue;
            freq[child]--;
            dfs(child, freq, graph, len + 1);
            freq[child]++;
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> freq;
        n = nums.size();
        for (auto i : nums) freq[i]++;
        for (auto& p : freq) {
            int x = p.first;
            graph[x] = vector<int>();
        }
        for (auto& p : freq) {
            for (auto& q : freq) {
                // if(p==q)continue;
                int x = p.first, y = q.first;
                if (isSqr(x + y))
                    graph[x].push_back(y);
            }
        }
        for (auto& p : freq) {
            int x = p.first;
            freq[x]--;
            dfs(x, freq, graph, 1);
            freq[x]++;
        }
        return ans;
    }
};
