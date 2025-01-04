class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& vec: times){
            adj[vec[0]].push_back({vec[1],vec[2]});
        }
        ///src--;
        ///dijkstra
        vector<int>distances(n+1,INT_MAX);
        vector<int> visited(n+1,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        distances[src]=0;
       /// visited[src]=1;
        pq.push({0,src});
        while(!pq.empty()){
            int par_dist=pq.top().first;
            int par_vert=pq.top().second;
            pq.pop();
            if(visited[par_vert])continue;
            visited[par_vert]=1;
            for(auto pr: adj[par_vert]){
                int child_dist=pr.second;
                int child_vert=pr.first;
                if(distances[par_vert]+child_dist<distances[child_vert]){
                    distances[child_vert]=distances[par_vert]+child_dist;
                    pq.push({distances[child_vert],child_vert});
                }
            }
        }
        int ans=-1;
        for(int i=1;i<n+1;i++){
            if(distances[i]==INT_MAX)return -1;
            ans=max(ans,distances[i]);
        }
        return ans;
        
    }
};