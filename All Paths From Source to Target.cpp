class Solution {
public:
    void dfs(vector<vector<int>>&graph,vector<vector<int>>&ans,vector<int>temp,int start,int end){
        temp.push_back(start);
        if(start==end){
            ans.push_back(temp);
            return;
        }
        for(auto i : graph[start]){
            dfs(graph,ans,temp,i,end);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n=graph.size();
        dfs(graph,ans,{},0,n-1);
        return ans;


        
    }
};