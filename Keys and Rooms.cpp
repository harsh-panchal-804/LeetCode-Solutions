class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,false);
        queue<int> queue;
        queue.push(0);
        while(!queue.empty()){
            int node=queue.front();
            queue.pop();
            vis[node]=true;
            for(auto & child:rooms[node]){
                if(vis[child])continue;
                queue.push(child);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i])return false;
        }
        return true;
        
    }
};