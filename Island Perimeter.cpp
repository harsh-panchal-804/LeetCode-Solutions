class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                ans+=4;
                for(auto di :dir){
                    int x=i+di.first;
                    int y=j+di.second;
                    if(x>=0 && y>=0 && x<grid.size()&& y<grid[0].size()&&grid[x][y]==1)ans--;
                }}
            }
        }
        return ans;
        
    }
};