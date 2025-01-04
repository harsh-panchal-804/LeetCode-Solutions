class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
        vector<int> distances(n,INT_MAX);
        distances[node1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,node1});
        while(!pq.empty()){
            auto [par_dist,par]=pq.top();
            pq.pop();
            if(par_dist>distances[par])continue;
            for(auto & child:adj[par]){
                if(distances[par]+1<distances[child]){
                    distances[child]=distances[par]+1;
                    pq.push({distances[child],child});
                }
            }
        }
        vector<int> dist(n,INT_MAX);
        vector<int> visited(n,0);
        dist[node2]=0;
        visited[node2]=1;
        queue<int> queue;
        queue.push(node2);
        while(!queue.empty()){
            int node=queue.front();
            queue.pop();
            for(auto & child:adj[node]){
                if(visited[child])continue;
                if(dist[node]+1<dist[child]){
                    visited[child]=1;
                    dist[child]=dist[node]+1;
                    queue.push(child);
                }
            }
        }
        int answer = -1;
        int minDist = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (dist[i] != INT_MAX && distances[i] != INT_MAX) {
                int maxDist = max(dist[i], distances[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    answer = i;
                }
            }
        }
        return answer;
    }
};