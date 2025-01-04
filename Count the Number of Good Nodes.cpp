class Solution {
public:
    // int dfs(vector<vector<int>> & adj,vector<int>&sizee,int node,vector<int>&visited){
    //     int curr=1;
    //     visited[node]=1;
    //     for(auto child: adj[node]){
    //         curr+=dfs(adj,sizee,child,visited);
    //     }
    //     sizee[node]=curr;
    //     return curr;
    // }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        vector<int> visited(n+1,0);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>sizee(n+1,1);
        function<void(int,int)> dfs=[&](int node,int parent){
            for(auto child:adj[node]){
                if(child==parent)continue;
                dfs(child,node);
                sizee[node]+=sizee[child];
            }
        };
        dfs(0,-1);
        // for(auto i : sizee){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        // for(int i=0;i<n+1;i++){
        //     for(auto j: adj[i]){
        //         cout<<j<<" ";
        //     }
        //     cout<<"\n";
        // }
        int ans=0;
        function<void(int,int)> func=[&](int node,int par){
            unordered_set<int> set;
            for(auto child: adj[node]){
                if(child==par)continue;
                set.insert(sizee[child]);
            }
            if(set.size()<2){
                ans++;
            }
            for(auto child:adj[node]){
                if(child!=par){
                    func(child,node);
                }
            }
        };
        func(0,-1);
        return ans;
        
    }
};