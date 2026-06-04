class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0 || nums[i] > n) {
                nums[i] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            int absIdx = abs(nums[i]);
            if (absIdx > 0 && absIdx <= n) {
                if (nums[absIdx - 1] > 0) {
                    nums[absIdx - 1] *= -1;
                } else if (nums[absIdx - 1] == 0) {
                    nums[absIdx - 1] = -n - 1;
                }
                while (res < n && nums[res] < 0) {
                    res++;
                }
            }
        }
        return res + 1;
    }
};