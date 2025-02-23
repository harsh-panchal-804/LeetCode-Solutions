class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    int n;
    vector<pair<int, tuple<int, int, int>>> adj;
    
    int kruskal(int b1, int b2) {
        DSU d(n);
        int totalCost = 0, edgeCount = 0;
        for (auto &edgeData : adj) {
            int cost = edgeData.first;
            auto t = edgeData.second;
            int u = get<0>(t);
            int v = get<1>(t);
            if ((u == b1 && v == b2) || (v == b1 && u == b2))
                continue;
            if (d.find(u) != d.find(v)) {
                d.Union(u, v);
                totalCost += cost;
                edgeCount++;
            }
        }
        return (edgeCount == n - 1) ? totalCost : INT_MAX;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
        this->n = n;
        adj.clear();
        for (int i = 0; i < edges.size(); i++) {
            adj.push_back({edges[i][2], {edges[i][0], edges[i][1], i}});
        }
        vector<vector<int>> ans(2);
        sort(adj.begin(), adj.end());
        int mstCost = kruskal(-1, -1);
        for (int i = 0; i < edges.size(); i++) {
            int costWithoutEdge = kruskal(edges[i][0], edges[i][1]);
            if (costWithoutEdge > mstCost) {
                ans[0].push_back(i);
            } else {
                DSU d(n);
                d.Union(edges[i][0], edges[i][1]);
                int totalCost = edges[i][2];
                int edgeCount = 1;
                for (auto &edgeData : adj) {
                    int cost = edgeData.first;
                    auto t = edgeData.second;
                    int u = get<0>(t);
                    int v = get<1>(t);
                    if (d.find(u) != d.find(v)) {
                        d.Union(u, v);
                        totalCost += cost;
                        edgeCount++;
                    }
                }
                if (edgeCount == n - 1 && totalCost == mstCost)
                    ans[1].push_back(i);
            }
        }
        return ans;
    }
};
