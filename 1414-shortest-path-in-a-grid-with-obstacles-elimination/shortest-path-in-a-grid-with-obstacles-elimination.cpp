class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        queue<tuple<int,int,int,int>> q; 
        q.push({0, 0, k, 0});
        vector<vector<int>> vis(m, vector<int>(n, -1));
        vis[0][0] = k;
        while(!q.empty()){
            auto [x, y, remain, steps] = q.front();
            q.pop();
            if(x == m - 1 && y == n - 1)
                return steps;
            for(auto dir : dirs){
                int nx = x + dir.first;
                int ny = y + dir.second;
                if(nx >= 0 && ny >= 0 && nx < m && ny < n){
                    int newK = remain;
                    if(grid[nx][ny] == 1){
                        if(newK > 0)
                            newK--;
                        else 
                            continue;
                    }
                    if(vis[nx][ny] != -1 && vis[nx][ny] >= newK)
                        continue;
                    vis[nx][ny] = newK;
                    q.push({nx, ny, newK, steps + 1});
                }
            }
        }
        return -1;
    }
};
