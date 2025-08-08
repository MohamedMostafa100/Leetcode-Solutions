class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int res = 0;
        vector<vector<int>> dp(fruits.size(), vector<int>(fruits.size(), -1));
        for (int i = 0; i < fruits.size(); i++) {
            res += fruits[i][i];
        }
        res += solve1(fruits, dp, 0, fruits.size() - 1, 0);
        res += solve2(fruits, dp, fruits.size() - 1, 0, 0);
        return res;
    }

private:
    int solve1(vector<vector<int>>& fruits, vector<vector<int>>& dp, int i,
               int j, int moves) {
        if (i == fruits.size() - 1 && j == fruits.size() - 1 &&
            moves == fruits.size() - 1) {
            return 0;
        }
        if (i == fruits.size() || j < 0 || j == fruits.size() ||
            moves > fruits.size() - 1 || i >= j) {
            return -2;
        }
        if (dp[i][j] == -1) {
            dp[i][j] = fruits[i][j];
            int path1 = solve1(fruits, dp, i + 1, j - 1, moves + 1);
            int path2 = solve1(fruits, dp, i + 1, j, moves + 1);
            int path3 = solve1(fruits, dp, i + 1, j + 1, moves + 1);
            int maxPath = max({path1, path2, path3});
            if (maxPath != -2) {
                dp[i][j] += maxPath;
            } else {
                dp[i][j] = -2;
            }
        }
        return dp[i][j];
    }

    int solve2(vector<vector<int>>& fruits, vector<vector<int>>& dp, int i,
               int j, int moves) {
        if (i == fruits.size() - 1 && j == fruits.size() - 1 &&
            moves == fruits.size() - 1) {
            return 0;
        }
        if (i == fruits.size() || i < 0 || j == fruits.size() ||
            moves > fruits.size() - 1 || i <= j) {
            return -2;
        }
        if (dp[i][j] == -1) {
            dp[i][j] = fruits[i][j];
            int path1 = solve2(fruits, dp, i - 1, j + 1, moves + 1);
            int path2 = solve2(fruits, dp, i, j + 1, moves + 1);
            int path3 = solve2(fruits, dp, i + 1, j + 1, moves + 1);
            int maxPath = max({path1, path2, path3});
            if (maxPath != -2) {
                dp[i][j] += maxPath;
            } else {
                dp[i][j] = -2;
            }
        }
        return dp[i][j];
    }
};