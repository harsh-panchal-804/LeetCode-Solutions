class Solution {
public:
    void dfs(int node , vector<int>&vis , vector<vector<int>> adj)
    {
        vis[node] = 1;
        for(auto it : adj[node])
        {
            if(vis[it]==0)
            {
                dfs(it,vis,adj);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(int i = 0 ; i < stones.size() ; i++)
        {
            for(int j = i+1 ; j<stones.size() ; j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0 ;
        for(int i = 0 ; i < stones.size() ; i++)
        {
            if(vis[i]==0)
            {
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return stones.size() - cnt;
    }
};