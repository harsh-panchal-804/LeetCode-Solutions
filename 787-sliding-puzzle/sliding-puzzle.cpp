class Solution {
public:
    vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 0}};
    bool equal(vector<vector<int>>& a, vector<vector<int>>& goal) {
        return a == goal;
    }
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int slidingPuzzle(vector<vector<int>>& board) {
        int x, y;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++)
                if (board[i][j] == 0) {
                    x = i;
                    y = j;
                }
        }
        queue<tuple<vector<vector<int>>, pair<int, int>, int>> queue;
        queue.push({board, {x, y}, 0});
        map<vector<vector<int>>, bool> vis;
        while (!queue.empty()) {
            auto front = queue.front();
            queue.pop();
            vector<vector<int>> board;
            pair<int, int> pos;
            int lvl;
            tie(board, pos, lvl) = front;
            int x = pos.first;
            int y = pos.second;
            if (equal(board, goal))
                return lvl;
            if (vis[board])
                continue;
            vis[board] = true;
            for (auto dir : dirs) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx >= 0 && ny >= 0 && nx < 2 && ny < 3) {
                    vector<vector<int>> new_board = board;
                    swap(new_board[nx][ny], new_board[x][y]);
                    queue.push({new_board, {nx, ny}, lvl + 1});
                }
            }
        }
        return -1;
    }
};