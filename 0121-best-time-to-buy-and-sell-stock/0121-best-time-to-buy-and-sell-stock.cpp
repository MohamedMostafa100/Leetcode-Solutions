class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int sell = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            res = max(res, prices[i] - sell);
            sell = min(sell, prices[i]);
        }
        return res;
    }
};