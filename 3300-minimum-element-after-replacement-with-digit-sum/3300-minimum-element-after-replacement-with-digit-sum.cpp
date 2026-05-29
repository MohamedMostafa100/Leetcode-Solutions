class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            res = min(res, sumDigits(nums[i]));
        }
        return res;
    }
private:
    int sumDigits(int x)
    {
        int res = 0;
        while(x > 0)
        {
            res += (x % 10);
            x /= 10;
        }
        return res;
    }
};