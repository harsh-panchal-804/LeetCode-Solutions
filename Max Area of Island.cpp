class Solution {
public:
    int temp=0;
    vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(int i,int j,vector<vector<int>>&grid){
        int area=0;
        queue<pair<int,int>> queue;
        grid[i][j]='.';
        area++;
        queue.push({i,j});
        while(!queue.empty()){
            auto i = queue.front().first;
            auto j=queue.front().second;
            
            
            queue.pop();
            for(auto  dir:dirs){
                int x=i+dir.first;
                int y=j+dir.second;
                if(x>=0 && y>=0 &&x<grid.size()&&y<grid[0].size()&& grid[x][y]==1){
                    queue.push({x,y});
                    grid[x][y]='.';
                    area++;
                    
                }
                temp=max(temp,area);
                
                

            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ///grid[i][j]='.';
                    bfs(i,j,grid);
                }
            }
        }
        return temp;
        
    }
};