class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
        map<string,vector<pair<string,double>>> adj;
        int n=eq.size();
        for(int i=0;i<n;i++){
            adj[eq[i][0]].push_back({eq[i][1],val[i]});
            adj[eq[i][1]].push_back({eq[i][0],1/val[i]});

        }
        vector<double> ans;
       
        function<double(string,string)>bfs=[&](string src,string dst){
            unordered_map<string,int> visited;
            queue<pair<string,double>> queue;
            queue.push({src,1.0});
            while(!queue.empty()){
                auto [ node,ans]=queue.front();
                queue.pop();
                if(node==dst)return ans;
                for(auto pr: adj[node]){
                    if(!visited[pr.first]){
                        queue.push({pr.first,ans*pr.second});
                        visited[pr.first]=1;
                    }
                }
            }
            return -1.0;
            
        };
        for(auto & qr: q){
            if(!adj.count(qr[0]) || !adj.count(qr[1])){
                ans.push_back(-1);
            }
            else{
                double res=bfs(qr[0],qr[1]);
                ans.push_back(res);
            }
        }
        return ans;
        
        
    }
};