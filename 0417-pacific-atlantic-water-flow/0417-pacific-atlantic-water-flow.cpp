class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> res;
    vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
    vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));

    for (int i = 0; i < heights[0].size(); i++)
    {
        touchesPacific(heights, pacific, 0, i);
    }

    for (int i = 1; i < heights.size(); i++)
    {
        touchesPacific(heights, pacific, i, 0);
    }

    for (int i = 0; i < heights[0].size(); i++)
    {
        touchesAtlantic(heights, atlantic, heights.size() - 1, i);
    }

    for (int i = 0; i < heights.size(); i++)
    {
        touchesAtlantic(heights, atlantic, i, heights[0].size() - 1);
    }

    for (int i = 0; i < heights.size(); i++)
    {
        for (int j = 0; j < heights[0].size(); j++)
        {
            if (pacific[i][j] && atlantic[i][j])
            {
                res.push_back({ i,j });
            }

        }
    }
    return res;
}

private:
    void touchesPacific(vector<vector<int>>& heights, vector<vector<bool>>& pacific, int i, int j)
{

    pacific[i][j] = true;

    if (j + 1 < heights[0].size() && heights[i][j + 1] >= heights[i][j] && !pacific[i][j + 1])
    {
        touchesPacific(heights, pacific, i, j + 1);
    }
    if (j - 1 >= 0 && heights[i][j - 1] >= heights[i][j] && !pacific[i][j - 1])
    {
        touchesPacific(heights, pacific, i, j - 1);
    }
    if (i + 1 < heights.size() && heights[i + 1][j] >= heights[i][j] && !pacific[i + 1][j])
    {
        touchesPacific(heights, pacific, i + 1, j);
    }
    if (i - 1 >= 0 && heights[i - 1][j] >= heights[i][j] && !pacific[i - 1][j])
    {
        touchesPacific(heights, pacific, i - 1, j);
    }
}

    void touchesAtlantic(vector<vector<int>>& heights, vector<vector<bool>>& atlantic, int i, int j)
{
    atlantic[i][j] = true;

    if (j + 1 < heights[0].size() && heights[i][j + 1] >= heights[i][j] && !atlantic[i][j + 1])
    {
        touchesAtlantic(heights, atlantic, i, j + 1);
    }
    if (j - 1 >= 0 && heights[i][j - 1] >= heights[i][j] && !atlantic[i][j - 1])
    {
        touchesAtlantic(heights, atlantic, i, j - 1);
    }
    if (i + 1 < heights.size() && heights[i + 1][j] >= heights[i][j] && !atlantic[i + 1][j])
    {
        touchesAtlantic(heights, atlantic, i + 1, j);
    }
    if (i - 1 >= 0 && heights[i - 1][j] >= heights[i][j] && !atlantic[i - 1][j])
    {
        touchesAtlantic(heights, atlantic, i - 1, j);
    }
}
};