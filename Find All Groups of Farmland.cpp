class Solution {
public:
    vector<pair<int,int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};
    vector<int> bfs(int i,int j,vector<vector<int>>& land){
        queue<pair<int,int>>queue;
        int r1=i;
        int c1=j;
        int r2=i;
        int c2=j;
        land[i][j]='.';
        queue.push({i,j});
        while(!queue.empty()){
            int i=queue.front().first;
            int j=queue.front().second;
            queue.pop();
            for(auto dir: dirs){
                int x=i+dir.first;
                int y=j+dir.second;
                if(x>=0 && y>=0 && x<land.size()&&y<land[0].size()&&land[x][y]==1){
                    queue.push({x,y});
                    land[x][y]='.';
                    // r1=min(r1,x);
                    // c1=min(c1,y);
                    r2=max(r2,x);
                    c2=max(c2,y);
                }
            }
        }
        return {r1,c1,r2,c2};

    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[0].size();j++){
                if(land[i][j]==1){
                    ///land[i][j]='.';
                    ans.push_back(bfs(i,j,land));
                }
            }
        }
        return ans;
        
    }
};