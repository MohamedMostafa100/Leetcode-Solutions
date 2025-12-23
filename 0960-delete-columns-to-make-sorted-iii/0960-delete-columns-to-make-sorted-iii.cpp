class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        vector<int> dp(strs[0].size(), 1);
        for(int i = strs[0].size() - 2; i >= 0; i--)
        {
            for(int j = i + 1; j < strs[0].size(); j++)
            {
                bool violation = false;
                for(int k = 0; k < strs.size(); k++)
                {
                    if(strs[k][i] > strs[k][j])
                    {
                        violation = true;
                        break;
                    }
                }
                if(!violation)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        for(int i = 0; i < dp.size(); i++)
        {
            res = max(res, dp[i]);
        }
        return strs[0].size() - res;
    }
};