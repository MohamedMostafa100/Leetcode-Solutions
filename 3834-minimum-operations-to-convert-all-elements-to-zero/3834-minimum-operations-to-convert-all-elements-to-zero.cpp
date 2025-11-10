class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        stack<int> stk;
        for(int i = 0; i < nums.size(); i++)
        {
            while(!stk.empty() && nums[i] < stk.top())
            {
                stk.pop();
            }
            if((stk.empty() || nums[i] > stk.top()) && nums[i] > 0)
            {
                stk.push(nums[i]);
                res++;
            }
        }
        return res;
    }
};