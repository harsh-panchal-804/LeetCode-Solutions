class Solution {
public:
    int count=0;
    void dfs(int src,int par,vector<int> &visited, set<vector<int>> &set,vector<vector<int>>&adj){
        visited[src]=1;
        for(auto child:adj[src]){
            if(!visited[child]&& child!=par){
                if(set.count({src,child})){
                    count++;
                }
                dfs(child,src,visited,set,adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> visited(n,0);
        vector<vector<int>> adj(n);
        set<vector<int>> set;
        for(auto i :connections){
            int u=i[0];
            int v=i[1];
            set.insert({u,v});
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int src=0;
        int par=-1;
        dfs(src,par,visited,set,adj);
        return count;
    }
};