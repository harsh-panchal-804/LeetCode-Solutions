class Solution {
public:
    int n;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>>& grid, int i, int j, int islandId) {

        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1)
            return 0;
        grid[i][j] = islandId;
        int area = 1;
        for (auto& d : directions) {
            int ni = i + d.first, nj = j + d.second;
            area += dfs(grid, ni, nj, islandId);
        }
        return area;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> islandArea;
        int islandId = 2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j, islandId);
                    islandArea[islandId] = area;
                    islandId++;
                }
            }
        }

        int maxArea = 0;
        if (islandArea.empty()) {
            return 1;
        }

        for (auto& entry : islandArea) {
            maxArea = max(maxArea, entry.second);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int potentialArea = 1;
                    unordered_set<int> seen;

                    for (auto& d : directions) {
                        int ni = i + d.first, nj = j + d.second;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                            grid[ni][nj] > 1) {
                            seen.insert(grid[ni][nj]);
                        }
                    }
                    for (int id : seen) {
                        potentialArea += islandArea[id];
                    }
                    maxArea = max(maxArea, potentialArea);
                }
            }
        }
        return maxArea;
    }
};
