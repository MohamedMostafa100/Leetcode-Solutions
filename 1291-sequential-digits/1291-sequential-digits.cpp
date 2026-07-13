class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for(char i = 1; i < 10; i++)
        {
            char cur = i;
            int curNum = i;
            while(curNum <= high && cur <= 9)
            {
                if(curNum >= low)
                {
                    res.push_back(curNum);
                }
                cur++;
                curNum = curNum * 10 + cur;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};