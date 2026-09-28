class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int cur = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                cur++;
                res = max(res, cur);
            }
            else if(s[i] == ')')
            {
                cur--;
            }
        }
        return res;
    }
};