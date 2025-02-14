class Solution {
public:
    vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n > 1 && m > 1 && grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
       
        vector<vector<int>> vis(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0});
        vis[0][0] = 0;
        
        while(!pq.empty()){
            auto [t, x, y] = pq.top();
            pq.pop();
            if(x == n - 1 && y == m - 1)
                return t;
            if(t > vis[x][y])
                continue;
            
            for(auto &d : dirs){
                int nx = x + d.first;
                int ny = y + d.second;
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                int nt = t + 1;
                if(nt < grid[nx][ny]){
                    nt = grid[nx][ny];
                    if((nt - t) % 2 == 0)
                        nt++;
                }
                if(nt < vis[nx][ny]){
                    vis[nx][ny] = nt;
                    pq.push({nt, nx, ny});
                }
            }
        }
        return -1;
    }
};
