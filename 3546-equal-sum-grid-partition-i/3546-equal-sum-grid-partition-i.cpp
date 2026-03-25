class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long tot = 0;
        vector<long long> rowSums(grid.size(), 0);
        vector<long long> colSums(grid[0].size(), 0);
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                tot += grid[i][j];
                rowSums[i] += grid[i][j];
                colSums[j] += grid[i][j];
            }
        }
        int i = 0;
        int j = 0;
        long long preRow = 0;
        long long preCol = 0;
        while(i < grid.size() || j < grid[0].size())
        {
            if(i < grid.size())
            {
                preRow += rowSums[i];
                if(preRow == (tot - preRow))
                {
                    return true;
                }
                i++;
            }
            if(j < grid[0].size())
            {
                preCol += colSums[j];
                if(preCol == (tot - preCol))
                {
                    return true;
                }
                j++;
            }
        }
        return false;
    }
};