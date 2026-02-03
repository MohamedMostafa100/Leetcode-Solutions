class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = 0;
        int q = nums.size() - 1;
        while(p < q && (nums[p + 1] > nums[p] || nums[q - 1] < nums[q]))
        {
            if(nums[p + 1] > nums[p])
            {
                p++;
            }
            if(nums[q - 1] < nums[q])
            {
                q--;
            } 
        }
        if(p == 0 || q == nums.size() - 1 || p >= q)
        {
            return false;
        }
        for(int i = p + 1; i <= q; i++)
        {
            if(nums[i] >= nums[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};