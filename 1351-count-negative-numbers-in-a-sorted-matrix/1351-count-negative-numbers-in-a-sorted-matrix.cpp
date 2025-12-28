class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        int i = grid.size() - 1;
        int j = 0;
        while(i >= 0 && j < grid[0].size())
        {
            while(j < grid[0].size() && grid[i][j] >= 0)
            {
                j++;
            }
            res += grid[0].size() - j;
            i--;
        }
        return res;
    }
};