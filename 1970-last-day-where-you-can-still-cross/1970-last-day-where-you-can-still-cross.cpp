class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<int> parent(cells.size() + 2);
        vector<int> rank(cells.size() + 2, 0);
        vector<vector<bool>> grid(row, vector<bool>(col, false));
        int top = cells.size();
        int bottom = cells.size() + 1;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
        for (int i = top - 1; i >= 0; i--) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            int cell = r * col + c;
            grid[r][c] = true;
            if (r == 0) {
                unite(parent, rank, cell, top);
            } else if (r == row - 1) {
                unite(parent, rank, cell, bottom);
            }
            for (int j = 0; j < 4; j++) {
                int newR = r + dirs[j][0];
                int newC = c + dirs[j][1];
                int newCell = newR * col + newC;
                if (newR >= 0 && newR < row && newC >= 0 && newC < col &&
                    grid[newR][newC]) {
                    unite(parent, rank, cell, newCell);
                }
            }
            if (findParent(parent, top) ==
                findParent(parent, bottom)) {
                return i;
            }
        }
        return 0;
    }

private:
    int findParent(vector<int>& parent, int x) {

        while (x != parent[x]) {
            x = parent[x];
        }
        return x;
    }
    void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
        x = findParent(parent, x);
        y = findParent(parent, y);
        if(x == y)
        {
            return;
        }
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else if (rank[y] > rank[x]) {
            parent[x] = y;
        } else {
            parent[x] = y;
            rank[y]++;
        }
    }
};