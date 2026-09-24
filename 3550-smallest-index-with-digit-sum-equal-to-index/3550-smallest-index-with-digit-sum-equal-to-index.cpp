class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == sumDig(nums[i]))
            {
                return i;
            }
        }
        return -1;
    }
private:
    int sumDig(int num)
    {
        int res = 0;
        while(num > 0)
        {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
};