class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int x=bombs[i][0];
                int y=bombs[i][1];
                long long r1=bombs[i][2];
                int x2=bombs[j][0];
                int y2=bombs[j][1];
                double dist=llabs(x2-x)*llabs(x2-x)*1ll + llabs(y2-y)*llabs(y2-y)*1ll;
                dist=sqrt(dist);
                if(dist<=(long long)r1){
                    ///cout<<i<<"  "<<j<<"\n";
                    adj[i].push_back(j);
                    ///adj[j].push_back(i);
                }
            }
        }
        function<int(int)> bfs=[&](int src){
            int count=0;
            vector<int> visited(n,0);
            visited[src]=1;
            queue<int> queue;
            queue.push(src);
            while(!queue.empty()){
                int node=queue.front();
                queue.pop();
                count++;
                for(auto & child: adj[node]){
                    if(!visited[child]){
                        queue.push(child);
                        visited[child]=1;
                    }
                }
            }
            return count;
        };
        int to_det=1;
        int damage=0;
        for(int i=0;i<n;i++){
            int triggered=bfs(i);
            ///cout<<triggered<<"\n";
            if(triggered>damage){
                damage=triggered;
                to_det=i;
            }
        }
        return damage;
        
    }
};