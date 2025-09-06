class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int res = 1;
        long long n = num1;
        while(1)
        {
            n -= num2;
            if (n < res)
            {
                return -1;
            }
            else if(res >= __builtin_popcountll(n))
            {
                return res;
            }
            res++;
        }
        return res;
    }
};