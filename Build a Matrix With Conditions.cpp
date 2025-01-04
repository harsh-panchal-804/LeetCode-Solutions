class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowcond, vector<vector<int>>& colcond) {
        vector<vector<int>> adjrow(k+1);
        vector<int> indegree(k+1,0);
        for(auto i : rowcond){
            adjrow[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        vector<int> first_topo;
        queue<int> queue;
        for(int i=1;i<k+1;i++){
            if(indegree[i]==0){
                queue.push(i);
            }
        }
        while(!queue.empty()){
            int node=queue.front();
            queue.pop();
            first_topo.push_back(node);
            for(auto child : adjrow[node]){
                indegree[child]--;
                if(indegree[child]==0){
                    
                    queue.push(child);
                }
            }
        }
       
        indegree.clear();
        fill(indegree.begin(),indegree.end(),0);
    
        if(first_topo.size()!=k)return {};
        vector<vector<int>> adjcol(k+1);
        for(auto i : colcond){
            adjcol[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        for(int i=1;i<k+1;i++){
            if(indegree[i]==0){
                queue.push(i);
            }
        }
        vector<int> second_topo;
        while(!queue.empty()){
            int node=queue.front();
            queue.pop();
            second_topo.push_back(node);
            for(auto child : adjcol[node]){
                indegree[child]--;
                if(indegree[child]==0){
                    queue.push(child);
                }
            }
        }
        if(second_topo.size()!=k)return {};
        unordered_map<int,pair<int,int>> map;
        vector<vector<int>> dp(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            map[first_topo[i]].first=i;
        }
        for(int i=0;i<k;i++){
            map[second_topo[i]].second=i;
        }
        for(int i=1;i<=k;i++){
            int x=map[i].first;
            int y=map[i].second;
            dp[x][y]=i;
        }

        return dp;

        
    }
};