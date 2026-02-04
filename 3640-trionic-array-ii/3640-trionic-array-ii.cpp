class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long res = LLONG_MIN;
        long long suffAdd = 0;
        int i = 1;
        // Pass till we find the first strictly increasing sequence
        while (nums[i] <= nums[i - 1]) {
            i++;
        }
        while (nums[i] > nums[i - 1]) {
            suffAdd = max((long long)nums[i - 1], suffAdd + nums[i - 1]);
            i++;
        }
        while (i < nums.size()) {
            long long decSum = nums[i - 1];
            while (i < nums.size() && nums[i] < nums[i - 1]) {
                decSum += nums[i];
                i++;
            }
            if (i == nums.size()) {
                break;
            } else if (nums[i] == nums[i - 1]) {
                suffAdd = 0;
                // Pass till we find the first strictly increasing sequence
                while (i < nums.size() && nums[i] <= nums[i - 1]) {
                    i++;
                }
                while (i < nums.size() && nums[i] > nums[i - 1]) {
                    suffAdd =
                        max((long long)nums[i - 1], suffAdd + nums[i - 1]);
                    i++;
                }
                continue;
            }
            long long preAdd = nums[i];
            long long incSum = 0;
            long long tempAdd = 0;
            while (i < nums.size() && nums[i] > nums[i - 1]) {
                tempAdd = max((long long)nums[i - 1], tempAdd + nums[i - 1]);
                incSum += nums[i];
                preAdd = max(preAdd, incSum);
                i++;
            }
            res = max(res, suffAdd + decSum + preAdd);
            suffAdd = tempAdd;
        }
        return res;
    }
};