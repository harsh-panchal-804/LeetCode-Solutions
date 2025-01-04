class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        vector<int> indegree(num);
        for(auto i :pre){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int> queue;
        for(int i=0;i<num;i++){
            if(indegree[i]==0){
                queue.push(i);
            }
        }
        int ans=0;
        while(!queue.empty()){
            int node=queue.front();
            queue.pop();
            ans++;
            for(auto child: adj[node]){
                indegree[child]--;
                if(indegree[child]==0){
                    queue.push(child);
                }
            }
        }
        return ans==num;

        
    }
};