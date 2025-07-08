class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        vector<vector<int>> dp(events.size(), vector<int>(k, -1));
        std::sort(events.begin(), events.end());
        return solve(events, dp, k, 0, 0);
    }

private:
    int solve(vector<vector<int>>& events, vector<vector<int>>& dp, int& k,
              int i, int count) {
        if (i == events.size() || count == k) {
            return 0;
        }

        if (dp[i][count] == -1) {
            int j = i + 1;
            while (j < events.size() && events[j][0] <= events[i][1]) {
                j++;
            }
            int choose = events[i][2] + solve(events, dp, k, j, count + 1);
            int notChoose = solve(events, dp, k, i + 1, count);

            dp[i][count] = max(choose, notChoose);
        }

        return dp[i][count];
    }
};