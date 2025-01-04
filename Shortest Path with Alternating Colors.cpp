class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<tuple<int,int>>> adj(n);
        
        // Construct adjacency list for red edges
        for(auto & i : redEdges){
            int u = i[0];
            int v = i[1];
            int c = 1;  // Red edge
            adj[u].push_back({v, c});
        }
        
        // Construct adjacency list for blue edges
        for(auto & i : blueEdges){
            int u = i[0];
            int v = i[1];
            int c = 0;  // Blue edge
            adj[u].push_back({v, c});
        }
        
        // BFS to find the shortest alternating path
        function<int(int, int)> bfs = [&](int src, int dst) {
            queue<tuple<int, int, int>> queue; // (node, color, distance)
            queue.push({src, 1, 0});  // Start with a red edge
            queue.push({src, 0, 0});  // Start with a blue edge
            
            vector<vector<int>> visited(n, vector<int>(2, INT_MAX)); // visited[node][color]
            visited[src][0] = visited[src][1] = 0;
            
            while (!queue.empty()) {
                auto [node, prev_col, dist] = queue.front();
                queue.pop();
                
                for (auto [child, child_col] : adj[node]) {
                    if (child_col != prev_col && dist + 1 < visited[child][child_col]) {
                        visited[child][child_col] = dist + 1;
                        queue.push({child, child_col, dist + 1});
                    }
                }
            }
            
            return min(visited[dst][0], visited[dst][1]);
        };
        
        vector<int> ans;
        for (int dst = 0; dst < n; dst++) {
            int temp = bfs(0, dst);
            ans.push_back(temp == INT_MAX ? -1 : temp);
        }
        
        return ans;
    }
};
