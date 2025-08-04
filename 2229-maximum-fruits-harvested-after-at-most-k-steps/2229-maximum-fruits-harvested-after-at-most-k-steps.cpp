class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int res = 0;
        int l = 0;
        int r = 0;
        int sum = 0;
        for(int r = 0; r < fruits.size(); r++)
        {
            sum += fruits[r][1];
            while(l <= r && steps(fruits, startPos, l, r) > k)
            {
                sum -= fruits[l][1];
                l++;
            }
            res = max(res, sum);
        }
        return res;
    }
private:
    int steps(vector<vector<int>>& fruits, int& startPos, int l, int r)
    {
        int res = 0;
        if(fruits[r][0] <= startPos)
        {
            res = abs(startPos - fruits[l][0]);
        }
        else if(fruits[l][0] >= startPos)
        {
            res = abs(startPos - fruits[r][0]);
        }
        else
        {
            res = min(abs(startPos - fruits[l][0]), abs(startPos - fruits[r][0])) + fruits[r][0] - fruits[l][0];
        }
        return res;
    }
};