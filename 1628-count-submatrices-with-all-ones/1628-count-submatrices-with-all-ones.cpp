class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int res = 0;
        vector<vector<int>> widths(mat.size(),
                               vector<int>(mat[0].size(), 0));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 1)
                {
                    if(j == 0)
                    {
                        widths[i][j] = 1;
                    }
                    else
                    {
                        widths[i][j] = widths[i][j - 1] + 1;
                    }
                }
            }
            for (int j = 0; j < mat[i].size(); j++) {
                int minWidth = widths[i][j];
                for(int k = i; k >= 0; k--)
                {
                    minWidth = min(minWidth, widths[k][j]);
                    if(minWidth == 0)
                    {
                        break;
                    }
                    res += minWidth;
                }
            }
        }

        return res;
    }
};