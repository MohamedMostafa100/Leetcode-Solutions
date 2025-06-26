class Solution {
public:
    int longestSubsequence(string s, int k) {
        int res = 0;
        int curNum = 0;
        int curPower = 0;
        int n = s.length();

        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '0')
            {
                res++;
            }
            else if(curPower < 31 && curNum + pow(2, curPower) <= k)
            {
                res++;
                curNum += pow(2, curPower);
            }
            curPower++;
        }

        return res;
    }
};