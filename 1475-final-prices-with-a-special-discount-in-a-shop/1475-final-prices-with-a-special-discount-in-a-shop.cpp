class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int, int>> stk;
        vector<int> res(prices.size());
        for(int i = 0; i < prices.size(); i++)
        {
            while(!stk.empty() && prices[i] <= stk.top().first)
            {
                res[stk.top().second] = stk.top().first - prices[i];
                stk.pop();
            }
            stk.push(make_pair(prices[i], i));
        }
        while(!stk.empty())
        {
            res[stk.top().second] = stk.top().first;
            stk.pop();
        }
        return res;
    }
};