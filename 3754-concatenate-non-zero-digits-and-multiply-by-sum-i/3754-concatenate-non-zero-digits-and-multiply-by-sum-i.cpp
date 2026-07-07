class Solution {
public:
    long long sumAndMultiply(int n) {
        int num = 0;
        int multiplier = 1;
        int tot = 0;
        while(n > 0)
        {
            int rem = n % 10;
            if(rem > 0)
            {
                num = rem * multiplier + num;
                tot += rem;
                multiplier *= 10;
            }
            n /= 10;
        }
        return 1LL * num * tot;
    }
};