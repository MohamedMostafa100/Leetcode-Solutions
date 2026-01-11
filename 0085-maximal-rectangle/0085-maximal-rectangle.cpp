class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        vector<vector<int>> right(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> up(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> down(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = matrix[0].size() - 1; j >= 0; j--)
            {
                if(matrix[i][j] == '1')
                {
                    if(j == matrix[0].size() - 1)
                    {
                        right[i][j] = 1;
                    }
                    else
                    {
                        right[i][j] = right[i][j + 1] + 1;
                    }
                }
            }
        }
        for(int j = 0; j < matrix[0].size(); j++)
        {
            stack<int> stk;
            if(right[0][j] > 0)
            {
                up[0][j] = 1;
                stk.push(0);
            }
            for(int i = 1; i < matrix.size(); i++)
            {
                if(right[i][j] == 0)
                {
                    while(!stk.empty())
                    {
                        stk.pop();
                    }
                    continue;
                }
                up[i][j] = 1;
                while(!stk.empty() && right[i][j] <= right[stk.top()][j])
                {
                    up[i][j] += up[stk.top()][j];
                    stk.pop();
                }
                stk.push(i);
            }
        }
        for(int j = 0; j < matrix[0].size(); j++)
        {
            stack<int> stk;
            if(right[matrix.size() - 1][j] > 0)
            {
                down[matrix.size() - 1][j] = 1;
                stk.push(matrix.size() - 1);
            }
            for(int i = matrix.size() - 2; i >= 0; i--)
            {
                if(right[i][j] == 0)
                {
                    while(!stk.empty())
                    {
                        stk.pop();
                    }
                    continue;
                }
                down[i][j] = 1;
                while(!stk.empty() && right[i][j] <= right[stk.top()][j])
                {
                    down[i][j] += down[stk.top()][j];
                    stk.pop();
                }
                stk.push(i);
            }
        }
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                res = max(res, right[i][j] * (down[i][j] + up[i][j] - 1));
            }
        }
        return res;
    }
};