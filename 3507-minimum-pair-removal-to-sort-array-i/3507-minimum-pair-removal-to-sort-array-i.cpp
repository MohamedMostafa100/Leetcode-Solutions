class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int res = 0;
        while(!checkSorted(nums))
        {
            int minSum = INT_MAX;
            int minIndex = -1;
            for(int i = 0; i < nums.size() - 1; i++)
            {
                if(nums[i] + nums[i + 1] < minSum)
                {
                    minSum = nums[i] + nums[i + 1];
                    minIndex = i;
                }
            }
            nums[minIndex] = nums[minIndex] + nums[minIndex + 1];
            nums.erase(nums.begin() + minIndex + 1);
            res++;
        }
        return res;
    }
private:
    bool checkSorted(vector<int>& nums)
    {
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};