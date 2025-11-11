class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> freqs;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(strs.size(), -1)));
        for(int i = 0; i < strs.size(); i++)
        {
            int o = 0;
            int z = 0;
            for(int j = 0; j < strs[i].length(); j++)
            {
                if(strs[i][j] == '1')
                {
                    o++;
                }
                else
                {
                    z++;
                }
            }
            freqs.push_back({o, z});
        }
        return solve(freqs, dp, 0, 0, 0, n, m);
    }
private:
    int solve(vector<pair<int, int>>& freqs, vector<vector<vector<int>>>& dp, int i, int o, int z, int n, int m)
    {
        if(i == freqs.size())
        {
            return 0;
        }
        if(dp[o][z][i] == -1)
        {
            dp[o][z][i] = 0;
            if(o + freqs[i].first <= n && z + freqs[i].second <= m)
            {
                dp[o][z][i] = max(dp[o][z][i], solve(freqs, dp, i + 1, o + freqs[i].first, z + freqs[i].second, n, m) + 1);
            }
            dp[o][z][i] = max(dp[o][z][i], solve(freqs, dp, i + 1, o, z, n, m));
        }
        return dp[o][z][i];
    }
};