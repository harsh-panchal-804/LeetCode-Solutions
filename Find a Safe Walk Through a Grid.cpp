class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> visited(m, vector<int>(n, -1));
        q.push({grid[0][0]==1?health-1:health, {0, 0}});
        visited[0][0] = health;
        while (!q.empty()) {
            auto [curr_health, pos] = q.front();
            q.pop();
            int i = pos.first;
            int j = pos.second;
            if (i == m - 1 && j == n - 1) {
                if (curr_health >= 1) { 
                    ///cout<<curr_health;
                    return true;
                } 
            }
            for (auto& d : directions) {
                int ni = i + d.first;
                int nj = j + d.second;
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    int new_health = curr_health - grid[ni][nj];  
                    if (new_health >0 && new_health > visited[ni][nj]) {
                        visited[ni][nj] = new_health;
                        q.push({new_health, {ni, nj}});
                    }
                }
            }
        }
        return false;
    }
};
