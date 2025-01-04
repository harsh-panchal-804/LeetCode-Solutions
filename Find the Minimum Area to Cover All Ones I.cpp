class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minrow = INT_MAX, mincol = INT_MAX, maxrow = INT_MIN, maxcol = INT_MIN;
        int n = grid.size(), m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    minrow = min(minrow, i);
                    mincol = min(mincol, j);
                    maxrow = max(maxrow, i);
                    maxcol = max(maxcol, j);
                }
            }
        }
        
        return (maxrow - minrow + 1) * (maxcol - mincol + 1);
    }
};