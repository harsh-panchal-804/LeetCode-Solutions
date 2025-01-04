class Solution {
public:
    vector<pair<int,int>> dirs={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int,int>> queue;
        int n=grid.size();

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    queue.push({i,j});
                    grid[i][j]=0;
                }
                else{
                    grid[i][j]=-1;
                }
                
            }
        }


        while(!queue.empty()){
            int s=queue.size();
            for(int i=0;i<s;i++){
                
                int row=queue.front().first;
                int col=queue.front().second;
                queue.pop();
      
                for(auto dir: dirs){
                    int r=row+dir.first;
                    int c=col+dir.second;
                    int val=grid[row][col];
                    if(r>=0 && c>=0 && r<grid.size()&& c<grid[0].size()&& grid[r][c]==-1){
                        grid[r][c]=val+1;
                        queue.push({r,c});
                    }
                }
            }
        }
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[0].size();j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        priority_queue<vector<int>> pq;
       
        pq.push(vector<int>{grid[0][0], 0, 0}); 
        grid[0][0] = -1; 
      
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

      
            if (curr[1] == n - 1 && curr[2] == n - 1) {
                return curr[0];
            }

         
            for (auto& d : dirs) {
                int di = d.first + curr[1];
                int dj = d.second + curr[2];
                if (di>=0 && dj>=0 && di<grid.size()&& dj<grid[0].size() && grid[di][dj] != -1) {
                    
                    pq.push(vector<int>{min(curr[0], grid[di][dj]), di, dj});
                    grid[di][dj] = -1;
                }
            }
        }


        return -1;

        
    }
};