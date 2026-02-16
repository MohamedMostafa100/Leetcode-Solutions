class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        int mask = 1;
        for(int i = 0; i < 32; i++)
        {
            if(mask & n)
            {
                res |= (1 << (31 - i));
            }
            mask <<= 1;
        }
        return res;
    }
};