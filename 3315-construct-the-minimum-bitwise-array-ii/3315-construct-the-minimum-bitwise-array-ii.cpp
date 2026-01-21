class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 2)
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(resetBit(nums[i]));
            }
        }
        return res;
    }
private:
    int resetBit(int num)
    {
        int modified = 0;
        int mask = 2;
        int i = 1;
        while(true)
        {
            if(!(mask & num))
            {
                modified = ~(1 << (i - 1)) & num;
                break; 
            }
            mask <<= 1;
            i++;
        }
        return modified;
    }
};