class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> res(heights.size(), 0);
        stack<int> visible;
        visible.push(0);
        for(int i = 1; i < heights.size(); i++)
        {
            while(!visible.empty() && heights[i] > heights[visible.top()])
            {
                res[visible.top()]++;
                visible.pop();
            }
            if(!visible.empty())
            {
                res[visible.top()]++;
            }
            visible.push(i);
        }
        return res;
    }
};