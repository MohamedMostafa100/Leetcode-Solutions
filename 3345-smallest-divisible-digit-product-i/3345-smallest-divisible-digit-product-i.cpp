class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = n; i < n + 10; i++)
        {
            if(numProd(i) % t == 0)
            {
                return i;
            }
        }
        return 0;
    }
private:
    int numProd(int num)
    {
        int prod = 1;
        while(num > 0)
        {
            prod *= (num % 10);
            num /= 10;
        }
        return prod;
    }
};