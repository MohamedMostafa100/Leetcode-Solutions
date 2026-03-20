class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int res = 0;
        vector<pair<int, bool>> pre(grid.size(), {0, false});
        for(int j = 0; j < grid[0].size(); j++)
        {
            int tot = 0;
            bool x = false;
            for(int i = 0; i < grid.size(); i++)
            {
                if(grid[i][j] == 'X')
                {
                    pre[i].first += 1;
                    pre[i].second = true;
                }
                else if(grid[i][j] == 'Y')
                {
                    pre[i].first -= 1;
                }
                tot += pre[i].first;
                x |= pre[i].second;
                if(!tot && x)
                {
                    res++;
                }
            }
        }
        return res;
    }
};