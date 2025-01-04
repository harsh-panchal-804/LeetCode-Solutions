class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        vector<vector<pair<long long, long long>>> adj(n);
        
        for (auto &i : roads) {
            int u = i[0];
            int v = i[1];
            int c = i[2];
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        // Dijkstra to find the shortest path and count paths
        vector<long long> distances(n, LLONG_MAX);
        vector<long long> pathCount(n, 0);
        distances[0] = 0;
        pathCount[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [par_dist, par] = pq.top();
            pq.pop();

            if (par_dist > distances[par]) continue;

            for (auto &[child, cost] : adj[par]) {
                long long new_dist = par_dist + cost;

                if (new_dist < distances[child]) {
                    distances[child] = new_dist;
                    pathCount[child] = pathCount[par];  
                    pq.push({new_dist, child});
                } else if (new_dist == distances[child]) {
                    pathCount[child] = (pathCount[child] + pathCount[par]) % mod;
                }
            }
        }

        return pathCount[n-1];
    }
};
