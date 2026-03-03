class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        vector<int> pos(n, -1);
        for(int i = 0; i < n; i++)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(grid[i][j] == 1)
                {
                    pos[i] = j;
                    break;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            bool found = false;
            for(int j = i; j < n; j++)
            {
                if(pos[j] <= i)
                {
                    found = true;
                    for(int k = j; k > i; k--)
                    {
                        swap(pos[k], pos[k - 1]);
                        res++;
                    }
                    break;
                }
            }
            if(!found)
            {
                return -1;
            }
        }
        return res;
    }
};