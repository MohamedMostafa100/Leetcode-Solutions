class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int s1 = 0; s1 < (int)nums.size() - 2; s1++) {
            if(nums[s1] == 0)
            {
                continue;
            }
            int s3 = s1 + 2;
            for(int s2 = s1 + 1; s2 < (int)nums.size() - 1; s2++)
            {
                while(s3 < nums.size() && nums[s3] < nums[s1] + nums[s2])
                {
                    s3++;
                }
                res += s3 - s2 - 1;
            }
        }
        return res;
    }
};