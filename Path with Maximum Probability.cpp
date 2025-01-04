class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int dst) {
        vector<vector<pair<double,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double wt=succProb[i];
            adj[u].push_back({wt,v});
            adj[v].push_back({wt,u});
        }
        /// no visited array
        /// bfs
        vector<double> distance(n,0.0);
        distance[src]=1.0;
        queue<tuple<int,double>> queue;
        queue.push({src,1.0});
        while(!queue.empty()){
            auto [node,prob]=queue.front();
            queue.pop();
            if(prob==0.0)continue;
            for(auto [wt,child]:adj[node]){
                if(distance[node]*wt>distance[child]){
                    distance[child]=distance[node]*wt;
                    queue.push({child,distance[child]});
                }
            }
        }
        return distance[dst];
    }
};