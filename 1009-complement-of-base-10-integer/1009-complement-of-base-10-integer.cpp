class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
        {
            return 1;
        }
        unsigned int mask = 1 << 31;
        while(mask > 0 && !(mask & n))
        {
            mask >>= 1;
        }
        while(mask > 0)
        {
            n ^= mask;
            mask >>= 1;
        }
        return n;
    }
};