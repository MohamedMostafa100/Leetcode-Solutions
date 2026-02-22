class Solution {
public:
    int binaryGap(int n) {
        int res = 0;
        int mask = 1;
        char prev = -1;
        for(int i = 0; i < 32; i++)
        {
            if(mask & n)
            {
                if(prev != -1)
                {
                    res = max(res, i - prev);
                }
                prev = i;
            }
            mask <<= 1;
        }
        return res;
    }
};