class Solution {
public:
    vector<pair<int,int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(int i,int j,vector<vector<char>>&grid){
        queue<pair<int,int>> queue;
        grid[i][j]='.';
        queue.push({i,j});
        while(!queue.empty()){
            i=queue.front().first;
            j=queue.front().second;
            queue.pop();
            for(auto dir : dirs){
                int x= i+dir.first;
                int y=j+dir.second;
                if(x>=0&&y>=0&&x<grid.size()&&y<grid[0].size()&&grid[x][y]=='1'){          queue.push({x,y});
                grid[x][y]='.';
                    
                }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    islands++;
                    ////grid[i][j]='.';
                    bfs(i,j,grid);
                   
                }
            }
        }
        return islands;
        
    }
};