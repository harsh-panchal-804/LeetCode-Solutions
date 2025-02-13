#pragma GCC target("avx2")

class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int totalWalls = 0;

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (true) {

            vector<vector<pair<int, int>>> regions;
            vector<unordered_set<int>> frontiers;
            vector<int> wallsNeeded;

            vector<vector<bool>> visited(m, vector<bool>(n, false));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1 && !visited[i][j]) {
                        vector<pair<int, int>> region;
                        unordered_set<int> frontier;
                        int walls = 0;

                        queue<pair<int, int>> q;
                        q.push({i, j});
                        visited[i][j] = true;

                        while (!q.empty()) {
                            auto [x, y] = q.front();
                            q.pop();
                            region.push_back({x, y});

                            for (auto& d : dirs) {
                                int nx = x + d.first, ny = y + d.second;
                                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                                    continue;

                                if (grid[nx][ny] == 0) {
                                    walls++;
                                    frontier.insert(nx * n + ny);
                                }

                                else if (grid[nx][ny] == 1 &&
                                         !visited[nx][ny]) {
                                    visited[nx][ny] = true;
                                    q.push({nx, ny});
                                }
                            }
                        }
                        regions.push_back(region);
                        frontiers.push_back(frontier);
                        wallsNeeded.push_back(walls);
                    }
                }
            }

            if (regions.empty())
                break;

            int maxThreat = 0, targetRegion = -1;
            for (int k = 0; k < frontiers.size(); k++) {
                if (frontiers[k].size() > maxThreat) {
                    maxThreat = frontiers[k].size();
                    targetRegion = k;
                }
            }

            if (maxThreat == 0)
                break;

            totalWalls += wallsNeeded[targetRegion];

            for (auto& cell : regions[targetRegion]) {
                grid[cell.first][cell.second] = -1;
            }

            for (int k = 0; k < regions.size(); k++) {
                if (k == targetRegion)
                    continue;
                for (int code : frontiers[k]) {
                    int i = code / n, j = code % n;

                    if (grid[i][j] == 0)
                        grid[i][j] = 1;
                }
            }
        }

        return totalWalls;
    }
};
