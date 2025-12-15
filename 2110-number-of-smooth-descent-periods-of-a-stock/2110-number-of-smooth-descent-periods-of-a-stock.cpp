class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res = 1;
        int length = 1;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i - 1] - prices[i] == 1)
            {
                length++;
            }
            else
            {
                length = 1;
            }
            res += length;
        }
        return res;
    }
};