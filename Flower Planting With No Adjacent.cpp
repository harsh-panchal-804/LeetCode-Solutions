class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> visited(n+1,0);
        queue<int> queue;
        vector<vector<int>> adj(n+1);
        for(auto & e: paths){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n+1,0);
        auto bfs=[&](int src){
            queue.push(src);
             while(!queue.empty()){
            int node=queue.front();
            visited[node]=1;
            queue.pop();
            vector<int> used(5,0);
            for(auto child: adj[node]){
                if(ans[child]!=0){
                    used[ans[child]]=1;
                }
            }
            for(int i=1;i<=4;i++){
                if(used[i]==0){
                    ans[node]=i;
                    break;
                }
            }
            for(auto child : adj[node]){
                if(visited[child])continue;
                if(ans[child]==0){
                    queue.push(child);
                }
            }
        }
        };
       
        for(int i=1;i<=n;i++){
            if(ans[i]==0)bfs(i);
        }
        return vector<int>(ans.begin()+1,ans.end());
    }
};