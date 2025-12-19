class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long res = 0;
        long long sum = 0;
        long long windowSum = 0;
        int l = 0;
        vector<int> pre(prices.size(), 0);
        for(int i = 0; i < prices.size(); i++)
        {
            sum += (prices[i] * strategy[i]);
            windowSum += (prices[i] * strategy[i]);
            if(i >= k - 1)
            {
                pre[i] = windowSum;
                windowSum -= (prices[l] * strategy[l]);
                l++;
            }
        }
        res = sum;
        long long profit = 0;
        l = 0;
        for(int r = 0; r < prices.size(); r++)
        {
            if(r >= k / 2)
            {
                profit += prices[r];
            }
            if(r - l + 1 == k)
            {
                res = max(res, sum - pre[r] + profit);
                profit -= prices[l + (k / 2)];
                l++;
            }
        }
        return res;
    }
};