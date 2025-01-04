class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<vector<int>> adj(num);
        vector<int> indegree(num);
        for(auto i : pre){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int> queue;
        for(int i=0;i<num;i++){
            if(indegree[i]==0){
                queue.push(i);
            }
        }
        vector<int> ans;
        while(!queue.empty()){
            int node=queue.front();
            queue.pop();
            ans.push_back(node);
            for(auto child : adj[node]){
                indegree[child]--;
                if(indegree[child]==0){
                    queue.push(child);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==num)return ans;
        return {};
        
    }
};