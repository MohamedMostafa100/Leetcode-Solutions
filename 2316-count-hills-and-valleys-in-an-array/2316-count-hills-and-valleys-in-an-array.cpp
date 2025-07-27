class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            int border1 = i - 1;
            int border2 = i + 1;
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                border2++;
                i++;
            }
            if (border2 < nums.size()) {
                if ((nums[i] > nums[border1] && nums[i] > nums[border2]) ||
                    (nums[i] < nums[border1] && nums[i] < nums[border2])) {
                    res++;
                }
            }
        }
        return res;
    }
};