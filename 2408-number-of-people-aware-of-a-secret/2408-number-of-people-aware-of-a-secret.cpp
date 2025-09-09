class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long res = 0;
        int mod = 1000000007;
        vector<long long> tellDays(n + 1, 0);
        vector<long long> toAdd(n + 1, 0);
        toAdd[1] = 1;
        tellDays[1] = 1;
        for (int i = 1; i <= n; i++) {
            if (tellDays[i] != 0) {
                for (int j = i + delay; j < min(n + 1, i + forget); j++) {
                    toAdd[j] += tellDays[i] % mod;
                    tellDays[j] = (tellDays[j] + tellDays[i]) % mod;
                }
                if (i + forget <= n) {
                    toAdd[i + forget] -= tellDays[i];
                }
            }
            res = (res + toAdd[i]) % mod;
        }
        return (res + mod) % mod;
    }
};