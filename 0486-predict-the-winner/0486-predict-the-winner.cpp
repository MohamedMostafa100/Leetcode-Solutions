class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n % 2 == 0)
        {
            return true;
        }
        return solve(nums, 0, n - 1) >= 0;
    }
private:
    int solve(vector<int>& nums, int i, int j)
    {
        if(i == j)
        {
            return nums[i];
        }
        return max(nums[i] - solve(nums, i + 1, j), nums[j] - solve(nums, i, j - 1));
    }
};