class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 500000;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r)
            {
                int tot = nums[i] + nums[l] + nums[r];
                if(abs(target - tot) < abs(target - res))
                {
                    res = tot;
                }
                int sum1 = nums[i] + nums[l + 1] + nums[r];
                int sum2 = nums[i] + nums[l] + nums[r - 1];
                if(abs(sum1 - target) < abs(sum2 - target))
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return res;
    }
};