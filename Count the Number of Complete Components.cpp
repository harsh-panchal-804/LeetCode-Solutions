class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> visited(n,0);
        function<vector<int>(int start,vector<int> &temp)> dfs=[&](int start,vector<int> &temp){       visited[start]=1;
        temp.push_back(start);
        for(auto child: adj[start]){
            if(!visited[child]){
                    dfs(child,temp);
            }
        }
        return temp;
        };
        vector<vector<int>> list;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                vector<int> temp;
                dfs(i,temp);
                list.push_back(temp);
            }
        }
        int count=0;
        for(auto & ls:list){
            int n=ls.size();
            bool flag=true;
            for(auto & child:ls){
                if(adj[child].size()!=n-1){
                    flag=false;
                    break;
                }
            }
            if(flag)count++;
        }
        return count;

    }
};