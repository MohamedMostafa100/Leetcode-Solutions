class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;
        for(int i = num1; i <= num2; i++)
        {
            string strInt = to_string(i);
            for(int j = 1; j < strInt.length() - 1; j++)
            {
                if((strInt[j] > strInt[j - 1] && strInt[j] > strInt[j + 1]) || (strInt[j] < strInt[j - 1] && strInt[j] < strInt[j + 1]))
                {
                    res++;
                }
            }
        }
        return res;
    }
};