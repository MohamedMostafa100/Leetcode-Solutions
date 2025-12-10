#define MOD 1000000007
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        for(int i = 1; i < complexity.size(); i++)
        {
            if(complexity[i] <= complexity[0])
            {
                return 0;
            }
        }
        return fact(complexity.size() - 1);
    }
private:
    int fact(int n)
    {
        if(n == 0 || n == 1)
        {
            return 1;
        }
        return (n * 1LL * fact(n - 1)) % MOD;
    }
};