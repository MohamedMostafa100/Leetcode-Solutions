class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        char dir = 1;
        int i = 0;
        int j = 0;
        while(i < mat.size() && j < mat[0].size())
        {
            res.push_back(mat[i][j]);
            if(dir == 1)
            {
                if(i - 1 >= 0 && j + 1 < mat[0].size())
                {
                    i--;
                    j++;
                }
                else
                {
                    if(j != mat[0].size() - 1)
                    {
                        j++;
                    }
                    else
                    {
                        i++;
                    }
                    dir = 0;
                }
            }
            else
            {
                if(i + 1 < mat.size() && j - 1 >= 0)
                {
                    i++;
                    j--;
                }
                else
                {
                    if(i != mat.size() - 1)
                    {
                        i++;
                    }
                    else
                    {
                        j++;
                    }
                    dir = 1;
                }
            }
        }
        return res;
    }
};