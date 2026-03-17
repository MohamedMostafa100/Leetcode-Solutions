class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int, int>> prevHeights;
        for(int i = 0; i < m; i++)
        {
            vector<pair<int, int>> heights;
            vector<bool> seen(n, false);
            for(int j = 0; j < prevHeights.size(); j++)
            {
                if(matrix[i][prevHeights[j].second] == 1)
                {
                    heights.push_back({prevHeights[j].first + 1, prevHeights[j].second});
                    seen[prevHeights[j].second] = true;
                }
            }
            for(int j = 0; j < n; j++)
            {
                if(!seen[j] && matrix[i][j] == 1)
                {
                    heights.push_back({1, j});
                }
            }
            int sumHeight = 0;
            for(int j = 0; j < heights.size(); j++)
            {
                res = max(res, heights[j].first * (j + 1));
            }
            prevHeights = heights;
        }
        return res;
    }
};