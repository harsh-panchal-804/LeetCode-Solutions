
class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        // Initialize the adjacency matrix with infinity distances
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));

        // Distance to self is 0
        for (int i = 1; i <= n; i++) {
            dist[i][i] = 0;
        }

      
        for (int i = 1; i <= n - 1; i++) {
            dist[i][i + 1] = 1;
            dist[i + 1][i] = 1;
        }
        dist[x][y] = 1;
        dist[y][x] = 1;

        // Floyd-Warshall algorithm to find all pairs shortest paths
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Count the number of pairs for each distance
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (dist[i][j] <= n) {
                    ans[dist[i][j]]+=2;
                }
            }
        }

       
        return vector<int>(ans.begin() + 1, ans.end());
    }
};
