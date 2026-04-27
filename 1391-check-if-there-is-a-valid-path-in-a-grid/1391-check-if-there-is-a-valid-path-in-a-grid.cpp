class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> pipes = {{2, 3}, {0, 1}, {0, 3}, {0, 2}, {1, 3}, {1, 2}};
        function<int(int, int)> getDir = [&](int cur, int direction) -> int {
            if (direction == -2) {
                return pipes[cur - 1][0];
            } else if (direction == -1) {
                return pipes[cur - 1][1];
            } else if (direction == 0) {
                if (pipes[cur - 1][0] == 1) return pipes[cur - 1][1];
                else if (pipes[cur - 1][1] == 1) return pipes[cur - 1][0];
            } else if (direction == 1) {
                if (pipes[cur - 1][0] == 0) return pipes[cur - 1][1];
                else if (pipes[cur - 1][1] == 0) return pipes[cur - 1][0];
            } else if (direction == 2) {
                if (pipes[cur - 1][0] == 3) return pipes[cur - 1][1];
                else if (pipes[cur - 1][1] == 3) return pipes[cur - 1][0];
            } else {
                if (pipes[cur - 1][0] == 2) return pipes[cur - 1][1];
                else if (pipes[cur - 1][1] == 2) return pipes[cur - 1][0];
            }
            return -1;
        };
        function<bool(int, int, int)> dfs = [&](int i, int j, int direction) -> bool {
            if (i < 0 || i == m || j < 0 || j == n || (visited[i][j] && (i > 0 || j > 0))) {
                return false;
            }
            direction = getDir(grid[i][j], direction);
            if (direction == -1) {
                return false;
            }
            if (i == m - 1 && j == n - 1) {
                return true;
            }
            visited[i][j] = true;
            if (dfs(i + dirs[direction].first, j + dirs[direction].second, direction)) {
                return true;
            }
            return false;
        };
        return dfs(0, 0, -2) || dfs(0, 0, -1);
    }
};