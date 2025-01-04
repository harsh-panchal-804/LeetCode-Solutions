class Solution {
public:
    int findCheapestPrice(int n,vector<vector<int>>& flights,int src,int dst,int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &i: flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        queue<vector<int>> queue;/// child wt lvl
        queue.push({src,0,0});
        int ans=1e9;
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        while(!queue.empty()){
            int node=queue.front()[0];
            int wt=queue.front()[1];
            int lvl=queue.front()[2];
            queue.pop();
            if(lvl>k)continue;
            for(auto child: adj[node]){
                if(wt+child.second<dist[child.first]){
                    dist[child.first]=wt+child.second;
                    queue.push({child.first,wt+child.second,lvl+1});
                }
            }
        }
        return dist[dst]==INT_MAX? -1:dist[dst];

    }
};