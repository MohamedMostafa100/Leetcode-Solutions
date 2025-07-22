class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0;
        unordered_set<int> inSubarr;
        int sum = 0;
        int l = 0;
        for(int r = 0; r < nums.size(); r++)
        {
            while(inSubarr.find(nums[r]) != inSubarr.end())
            {
                sum -= nums[l];
                inSubarr.erase(nums[l]);
                l++;
            }
            sum += nums[r];
            inSubarr.insert(nums[r]);
            res = max(res, sum);
        }
        return res;
    }
};