class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int res = 0;
        sort(cost.begin(), cost.end());
        int i = cost.size() - 1;
        while(i >= 0)
        {
            if(i - 2 >= 0)
            {
                res += cost[i] + cost[i - 1];
                i -= 3;
            }
            else
            {
                res += cost[i];
                i--;
            }
        }
        return res;
    }
};