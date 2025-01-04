class Solution {
public:
    int m, n;

    void DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0) {
            return;
        }

        visited[i][j] = true;

        // Explore all adjacent 4 directions
        DFS(grid, i + 1, j, visited);
        DFS(grid, i - 1, j, visited);
        DFS(grid, i, j + 1, visited);
        DFS(grid, i, j - 1, visited);
    }

    int numOfIslandsUtil(vector<vector<int>>& grid) {
        int islands = 0;

        vector<vector<bool>> visited(m, vector<bool>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) { // non-visited land
                    islands++;
                    DFS(grid, i, j, visited);
                }
            }
        }

        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int islands = numOfIslandsUtil(grid);

        // No need to disconnect if already disconnected or empty
        if (islands == 0 || islands > 1)
            return 0;

        // Check if we can disconnect in one day
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) { // If it's land
                    grid[i][j] = 0; // Make it water

                    islands = numOfIslandsUtil(grid);

                    if (islands == 0 || islands > 1)
                        return 1;

                    grid[i][j] = 1; // Restore the land
                }
            }
        }

        return 2; // If unable to disconnect in one day, it must take two days
    }
};