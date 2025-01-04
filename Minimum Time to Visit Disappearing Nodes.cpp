class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges,
                            vector<int>& disappear) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& i : edges) {
            int u = i[0];
            int v = i[1];
            int c = i[2];
            adj[v].push_back({u, c});
            adj[u].push_back({v, c});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> distances(n, INT_MAX);
        int src = 0;
        distances[src] = 0;
        vector<int> visited(n, 0);
        pq.push({0, src});
        while (!pq.empty()) {
            auto [par_dist, par] = pq.top();
            pq.pop();
            if (visited[par])
                continue;
            visited[par] = 1;
            for (auto& [child, cost] : adj[par]) {
                if (par_dist + cost < distances[child] &&
                    par_dist + cost < disappear[child]) {
                    distances[child] = par_dist + cost;
                    pq.push({distances[child],child});
                }
            }
        }
        for(int i=0;i<n;i++)if(distances[i]==INT_MAX)distances[i]=-1;
        return distances;
    }
};