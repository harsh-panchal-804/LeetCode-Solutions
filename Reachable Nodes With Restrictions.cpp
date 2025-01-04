class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> visited(n);
        for(auto i: restricted)visited[i]=1;
        int ans=0;
        vector<vector<int>> adj(n);
        for(auto & e: edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        function<void(int,int)> dfs=[&](int node,int par){
            visited[node]=1;
            ans++;
            for(auto & child:adj[node]){
                if(!visited[child]){
                    dfs(child,node);
                }
            }
        };
        dfs(0,-1);
        return ans;
        
    }
};