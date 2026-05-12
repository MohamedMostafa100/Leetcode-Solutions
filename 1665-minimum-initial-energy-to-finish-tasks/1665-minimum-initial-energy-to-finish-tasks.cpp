class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int res = 0;
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b){
            int diff1 = a[1] - a[0];
            int diff2 = b[1] - b[0];
            if(diff1 > diff2)
            {
                return true;
            }
            else if(diff1 < diff2)
            {
                return false;
            }
            return a[0] < b[0];
        });
        int tot = 0;
        for(int i = 0; i < tasks.size(); i++)
        {
            int diff = max(tasks[i][1] - tot, 0);
            res += diff;
            tot += diff - tasks[i][0];
        }
        return res;
    }
};