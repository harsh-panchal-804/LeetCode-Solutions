class Solution {
public:
    vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int min=0;
        queue<pair<pair<int,int>,int>> queue;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                   queue.push({{i,j},0});
                   cout<<"df";
                }
            }
        }
        int ans=0;
     
        while(!queue.empty()){
            int r=queue.front().first.first;
            int c=queue.front().first.second;
            int min=queue.front().second;
            queue.pop();
            for(auto dir : dirs){
                int x=r+dir.first;
                int y=c+dir.second;
                if((x>=0&& y>=0 &&x<grid.size()&& y<grid[0].size()&& grid[x][y]==1)){
                    grid[x][y]=0;
                    queue.push({{x,y},min+1});/// use min+1 instead of min++ or ++min

                }
               
            }
            ans=min;

        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                 return -1;
                 
                }
            }
        }



        
        return ans;

        
    }
};