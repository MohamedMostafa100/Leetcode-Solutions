class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i <= n / 2; i++)
        {
            if(!containsZero(i) && !containsZero(n - i))
            {
                return {i, n - i};
            }
        }
        return {};
    }
private:
    bool containsZero(int x)
    {
        while(x > 0)
        {
            if(x % 10 == 0)
            {
                return true;
            }
            x /= 10;
        }
        return false;
    }
};