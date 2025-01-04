class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows=grid1.size();
        int col=grid1[0].size();
        vector<pair<int,int>> dirs={{-1,0},{1,0},{0,1},{0,-1}};
        set<pair<int,int>> set;
        function<bool(int,int)> bfs=[&](int x,int y){
            if(grid1[x][y]==0)return false;
            bool flag=true;
            set.insert({x,y});
            queue<pair<int,int>> queue;
            queue.push({x,y});
            grid2[x][y]=0;
            while(!queue.empty()){
                auto [i,j]=queue.front();
                queue.pop();
                for(auto [dx,dy]:dirs){
                    int ni=i+dx;
                    int jj=j+dy;
                    if(ni>=0&&jj>=0&&ni<rows&& jj<col&&grid2[ni][jj]==1 &&!set.count({ni,jj})){
                        if(grid1[ni][jj]==0)flag=false;
                        grid2[ni][jj]=0;
                        queue.push({ni,jj});
                        set.insert({ni,jj});
                    }
                }
            }
            return flag;
        };
        int count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if(grid2[i][j]==1 && !set.count({i,j})){
                   if(bfs(i,j))++count;
                }
            }
        }
        return count;
        
    }
};