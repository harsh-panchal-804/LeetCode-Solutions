class Solution {
public:
    void dijekstra(vector<int>& sd,int src,vector<vector<int>>& adj){
        priority_queue<pair<int,int>> pq;
        sd[src]=0;
        pq.push({0,0});
        while(!pq.empty()){
            int size=pq.size();
            while(size--){
                pair<int,int> p=pq.top();
                pq.pop();
                int node=p.second;
                int currDis=p.first;
                for(int i=0;i<adj[node].size();i++){
                    int nextNode=adj[node][i];
                    int finalDis=currDis+1;
                    if(finalDis<sd[nextNode]){
                        sd[nextNode]=finalDis;
                        pq.push({finalDis,nextNode});
                    }
                }
            }
        }
    }
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=patience.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> sd(n,INT_MAX);
        dijekstra(sd,0,adj);
        int ans=0;
        for(int i=1;i<n;i++){
            int maxTime=(2*sd[i])+1;
            if(patience[i]<(2*sd[i])){
                int extraP=((2*sd[i])-1)/patience[i];
                maxTime=(2*sd[i])+(extraP*patience[i])+1;
            }
            ans=max(ans,maxTime);
        }
        return ans;
    }
};