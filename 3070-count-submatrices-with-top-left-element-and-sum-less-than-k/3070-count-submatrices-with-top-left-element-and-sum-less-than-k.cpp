class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int res = 0;
        for(int j = 0; j < grid[0].size(); j++)
        {
            int tot = 0;
            if(j > 0 && (grid[0][j - 1] + grid[0][j] > k))
            {
                break;
            }
            for(int i = 0; i < grid.size(); i++)
            {
                if(j > 0)
                {
                    grid[i][j] += grid[i][j - 1];
                }
                tot += grid[i][j];
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