class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> reach(n,vector<int>(n,0));
        vector<vector<int>> adj(n);
        for(auto &i : prerequisites){
            adj[i[0]].push_back(i[1]);
        }
        for(int i=0;i<n;i++)reach[i][i]=1;
        function<void(int)> bfs=[&](int src){
            vector<int> visited(n,0);
            queue<int> queue;
            queue.push(src);
            while(!queue.empty()){
                int node=queue.front();
                queue.pop();
                visited[node]=1;
                for(auto & child:adj[node]){
                    if(!visited[child]){
                        visited[child]=1;
                        reach[src][child]=1;
                        queue.push(child);
                    }
                }
            }
        };
        for(int i=0;i<n;i++){
            bfs(i);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<reach[i][j]<<" ";
            }
            cout<<"\n";
        }
        int q=queries.size();
        vector<bool> ans;
        for(int i=0;i<q;i++){
            int start=queries[i][0];
            int end=queries[i][1];
            ans.push_back(reach[start][end]==1? true:false);
        }
        return ans;

    }
};