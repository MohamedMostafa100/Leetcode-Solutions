class Solution {
public:
    int numOfWays(int n) {
        long long abc = 6;
        long long aba = 6;
        for(int i = 1; i < n; i++)
        {
            long long temp1 = (abc * 2 + aba * 2) % 1000000007;
            long long temp2 = (abc * 2 + aba * 3) % 1000000007;
            abc = temp1;
            aba = temp2;
        }
        return (abc + aba) % 1000000007;
    }
};