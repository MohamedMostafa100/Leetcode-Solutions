#define MOD 1000000007
class Solution {
public:
    int concatenatedBinary(int n) {
        long long res = 1;
        int mask = 1 << 2;
        char shift = 2;
        for(int i = 2; i <= n; i++)
        {
            if(mask & i)
            {
                shift++;
                mask <<= 1;
            }
            res = (((res << shift) % MOD) + i) % MOD;
        }
        return res;
    }
};