class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1;
        int l = 0;
        int r = nums.size();
        while(l < r)
        {
            int mid = (l + r) / 2;
            if(target < nums[mid])
            {
                if(nums[l] > nums[mid] || target >= nums[l])
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else if(target > nums[mid])
            {
                if(nums[r - 1] < nums[mid] || target <= nums[r - 1])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            else
            {
                res = mid;
                break;
            }
        }
        return res;
    }
};