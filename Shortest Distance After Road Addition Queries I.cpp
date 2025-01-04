class Solution {
public:
    int bfs(int n, std::vector<int> query, std::vector<std::vector<int>>& graph) {
        graph[query[0]].push_back(query[1]);

        std::queue<std::pair<int, int>> q;
        q.push({0, 0});

        std::vector<bool> visited(n);

        while(!q.empty()) {
            int src = q.front().first;
            int val = q.front().second;
            q.pop();

            if(src == n - 1) return val;

            for(const int des : graph[src]) {
                if(!visited[des]) {
                    visited[des] = true;
                    q.push({des, val + 1});
                }
            }
        }

        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int s = queries.size();

        std::vector<int> ans(s);

        // Create graph
        std::vector<std::vector<int>> graph(n);
        for(int i = 0; i < n - 1; ++i) {
            graph[i].push_back(i + 1);
        }

        for(int i = 0; i < s; ++i) {
            ans[i] = bfs(n, queries[i], graph);
        }

        return ans;
    }
};