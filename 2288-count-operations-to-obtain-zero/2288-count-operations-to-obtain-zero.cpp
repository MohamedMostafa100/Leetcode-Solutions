class Solution {
public:
    int countOperations(int num1, int num2) {
        int res = 0;
        while(num1 > 0 && num2 > 0)
        {
            if(num1 > num2)
            {
                res += (num1 / num2);
                num1 -= num2 * (num1 / num2);
            }
            else if(num2 > num1)
            {
                res += (num2 / num1);
                num2 -= num1 * (num2 / num1);
            }
            else
            {
                res++;
                break;
            }
        }
        return res;
    }
};