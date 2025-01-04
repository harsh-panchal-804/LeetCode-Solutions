class Solution {
public:
    int dfs(int r,int c ,vector<vector<int>>&grid){
        if(r<0|| c<0|| r>=grid.size()|| c>=grid[0].size()|| grid[r][c]==0){
            return 0;
        }
        int temp=grid[r][c];
        grid[r][c]=0;
        int ans=max({dfs(r+1,c,grid),dfs(r-1,c,grid),dfs(r,c+1,grid),dfs(r,c-1,grid)});
        grid[r][c]=temp;
        return ans +temp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                count=max(count,dfs(i,j,grid));

            }
        }
        return count;

        
    }
};