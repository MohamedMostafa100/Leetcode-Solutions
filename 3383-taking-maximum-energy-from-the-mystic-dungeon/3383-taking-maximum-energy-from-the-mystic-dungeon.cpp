class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int res = INT_MIN;
        vector<int> dp;
        dp.push_back(energy[0]);
        for(int i = 1; i < energy.size(); i++)
        {
            if(i - k >= 0)
            {
                dp.push_back(max(energy[i], dp[i - k] + energy[i]));
            }
            else
            {
                dp.push_back(energy[i]);
            }
            if(energy.size() - i <= k)
            {
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};