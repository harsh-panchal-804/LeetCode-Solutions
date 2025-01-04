class Solution {
public:
    vector<pair<int,int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(int r,int c,vector<vector<int>>& grid){
        queue<pair<int,int>> queue;
        queue.push({r,c});
        grid[r][c]=0;
        while(!queue.empty()){
            r=queue.front().first;
            c=queue.front().second;
            queue.pop();
            for(auto dir: dirs){
                int x=r+dir.first;
                int y=c+dir.second;
                if(x>=0 && y>=0 && x<grid.size()&& y<grid[0].size()&&grid[x][y]==1){
                    queue.push({x,y});
                    grid[x][y]=0;
                }
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int count=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1)count++;
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if((i==0 || j==0 || i==row-1||j==col-1)&& grid[i][j]==1){
                    ///grid[i][j]=0;
                    bfs(i,j,grid);
                    
                    cout<<"call";
                }
            }
        }
        int count2=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1)count2++;
            }
        }
        ////cout<<count<<count2;
        return count2;

        
    }
};