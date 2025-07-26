class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long res = 0;
        vector<vector<int>> forbidden(n + 1);
        for(int i = 0; i < conflictingPairs.size(); i++)
        {
            forbidden[max(conflictingPairs[i][0], conflictingPairs[i][1])].push_back(min(conflictingPairs[i][0], conflictingPairs[i][1]));
        }
        int top1 = 0;
        int top2 = 0;
        vector<long long> bonus(n + 1, 0);
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j < forbidden[i].size(); j++)
            {
                if(forbidden[i][j] > top1)
                {
                    top2 = top1;
                    top1 = forbidden[i][j];
                }
                else if(forbidden[i][j] > top2)
                {
                    top2 = forbidden[i][j];
                }
            }
            res += i - (long long)top1;
            if(top1 > 0)
            {
                bonus[top1] += (long long)top1 - top2;
            }
        }
        long long maxBonus = 0;
        for(int i = 0; i < bonus.size(); i++)
        {
            maxBonus = max(maxBonus, bonus[i]);
        }
        return res + maxBonus;
    }
};