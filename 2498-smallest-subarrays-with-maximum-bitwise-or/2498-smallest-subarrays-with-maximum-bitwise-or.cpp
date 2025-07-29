class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> pre(nums.size());
        int orSum = 0;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            orSum |= nums[i];
            pre[i] = orSum;
        }
        int l = 0;
        orSum = 0;
        vector<int> bits(32, 0);
        for(int r = 0; r < nums.size(); r++)
        {
            orSum = computeBits(bits, 1, nums[r]);
            while(l <= r && orSum == pre[l])
            {
                res[l] = r - l + 1;
                orSum = computeBits(bits, -1, nums[l]);
                l++;
            }
        }
        return res;
    }
private:
    int computeBits(vector<int>& bits, int sign, int toAdd)
    {
        int res = 0;
        int mask = 1;
        for(int i = 31; i >= 0; i--)
        {
            if(toAdd & mask)
            {
                bits[i] += sign;
            }
            if(bits[i] > 0)
            {
                res += pow(2, 31 - i);
            }
            mask <<= 1;
        }
        return res;
    }
};