class Solution {
public:
    double fans = 0.0;
    int target;

    void dfs(int node, int parent, vector<vector<int>>& graph, double prob, int t) {
        int children = 0;
        for (int child : graph[node]) {
            if (child != parent) children++;
        }

        
        if (t == 0 || children == 0) {
            if (node == target) fans = prob;
            return;
        }

      
        for (int child : graph[node]) {
            if (child == parent) continue;
            dfs(child, node, graph, prob / children, t - 1);
        }
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int tar) {
        target = tar;
        vector<vector<int>> graph(n + 1);

     
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

       
        dfs(1, -1, graph, 1.0, t);
        
        return fans;
    }
};
