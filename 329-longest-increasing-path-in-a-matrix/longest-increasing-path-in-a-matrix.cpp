#pragma GCC target("avx2")

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> outdegree(m, vector<int>(n, 0));
        vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (auto& d : dirs) {
                    int ni = i + d.first, nj = j + d.second;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[i][j])
                        outdegree[i][j]++;
                }
            }
        }
        
    
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (outdegree[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        int level = 0;
      
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [i, j] = q.front();
                q.pop();
                
                for (auto& d : dirs) {
                    int ni = i + d.first, nj = j + d.second;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] < matrix[i][j]) {
                        outdegree[ni][nj]--;
                        if (outdegree[ni][nj] == 0) {
                            q.push({ni, nj});
                        }
                    }
                }
            }
            level++;  
        }
        
        return level;
    }
};
