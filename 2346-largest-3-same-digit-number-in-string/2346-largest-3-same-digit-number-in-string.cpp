class Solution {
public:
    string largestGoodInteger(string num) {
        char largestNum = 0;
        string goodStr = "";
        for(int i = 0; i < num.length() - 2; i++)
        {
            if(num[i] == num[i + 1] && num[i + 1] == num[i + 2] && num[i] == num[i + 2])
            {
                if(goodStr.length() == 0 || num[i] - '0' > largestNum)
                {
                    goodStr = num.substr(i, 3);
                    largestNum = num[i] - '0';
                }
            }
        }
        return goodStr;
    }
};