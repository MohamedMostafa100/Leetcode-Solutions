class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int res = 0;
        vector<int> preSum(grid.size(), 0);
        for(int j = 0; j < grid[0].size(); j++)
        {
            int tot = 0;
            if(preSum[0] + grid[0][j] > k)
            {
                break;
            }
            for(int i = 0; i < grid.size(); i++)
            {
                preSum[i] += grid[i][j];
                tot += preSum[i];
                if(tot > k)
                {
                    break;
                }
                res++;
            }
        }
        return res;
    }
};