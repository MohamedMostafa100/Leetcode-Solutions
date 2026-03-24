class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> res(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>> suf(grid.size(), vector<int>(grid[0].size()));
        long long prod = 1;
        for(int i = grid.size() - 1; i >= 0; i--)
        {
            for(int j = grid[0].size() - 1; j >= 0; j--)
            {
                suf[i][j] = prod;
                prod = (prod * grid[i][j]) % 12345;
            }
        }
        prod = 1;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                res[i][j] = (prod * suf[i][j]) % 12345;
                prod = (prod * grid[i][j]) % 12345;
            }
        }
        return res;
    }
};