class Solution {
public:
    int minOperations(string s) {
        int res1 = 0;
        int res2 = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if((s[i] == '1' && i % 2 == 0) || (s[i] == '0' && i % 2 == 1))
            {
                res1++;
            }
            else
            {
                res2++;
            }
        }
        return min(res1, res2);
    }
};