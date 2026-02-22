class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for(int i = left; i <= right; i++)
        {
            if(countBits(i) == 2 || countBits(i) == 3 || countBits(i) == 5 || countBits(i) == 7 || countBits(i) == 11 || countBits(i) == 13 || countBits(i) == 17 || countBits(i) == 19 || countBits(i) == 23 || countBits(i) == 29)
            {
                res++;
            }
        }
        return res;
    }
private:
    char countBits(int n)
    {
        char bits = 0;
        int mask = 1;
        for(int i = 0; i < 32; i++)
        {
            if(mask & n)
            {
                bits++;
            }
            mask <<= 1;
        }
        return bits;
    }
};