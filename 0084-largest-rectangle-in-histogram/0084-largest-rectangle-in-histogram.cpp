class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<pair<int, int>> stk;
        for(int i = 0; i < heights.size(); i++)
        {
            int firstIdx = i;
            while(!stk.empty() && heights[i] < stk.top().first)
            {
                int idx = stk.top().second;
                int h = stk.top().first;
                res = max(res, (i - idx) * h);
                firstIdx = idx;
                stk.pop();
            }
            stk.push({heights[i], firstIdx});
        }
        while(!stk.empty())
        {
            int idx = stk.top().second;
            int h = stk.top().first;
            res = max(res, ((int)heights.size() - idx) * h);
            stk.pop();
        }
        return res;
    }
};