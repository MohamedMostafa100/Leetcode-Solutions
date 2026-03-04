class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return b[0] > a[0];
        });
        res.push_back(intervals[0]);
        int l = 0;
        for(int r = 1; r < intervals.size(); r++)
        {
            if((res[l][1] >= intervals[r][0] && res[l][1] <= intervals[r][1]) || (intervals[r][1] >= res[l][0] && intervals[r][1] <= res[l][1]))
            {
                res[l][1] = max(intervals[r][1], res[l][1]);
            }
            else
            {
                res.push_back(intervals[r]);
                l++;
            }
        }
        return res;
    }
};