class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<vector<int>> dp(budget + 1, vector<int>(items.size(), -1));
        int minItem = 1500;
        unordered_map<int, int> divisors;
        unordered_map<int, int> freqs;
        for (int i = 0; i < items.size(); i++) {
            minItem = min(minItem, items[i][1]);
            freqs[items[i][0]]++;
        }
        for (auto& it1 : freqs) {
            divisors[it1.first] = 0;
            for (auto& it2 : freqs) {
                if(it2.first % it1.first == 0)
                {
                    divisors[it1.first] += it2.second;
                }
            }
            divisors[it1.first] = max(divisors[it1.first] - 1, 0);
        }
        return solve(items, dp, divisors, 0, 0, budget, minItem);
    }
private:
    int solve(vector<vector<int>>& items, vector<vector<int>>& dp, unordered_map<int, int>& divisors, int i, int curPrice, int budget, int minItem)
    {
        if(i == items.size())
        {
            return (budget - curPrice) / minItem;
        }
        if(dp[curPrice][i] == -1)
        {
            dp[curPrice][i] = 0;
            if(curPrice + items[i][1] <= budget)
            {
                dp[curPrice][i] = max(dp[curPrice][i], solve(items, dp, divisors, i + 1, curPrice + items[i][1], budget, minItem) + 1 + divisors[items[i][0]]);
            }
            dp[curPrice][i] = max(dp[curPrice][i], solve(items, dp, divisors, i + 1, curPrice, budget, minItem));
        }
        return dp[curPrice][i];
    }
};