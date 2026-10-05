class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0;
        int order = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                order++;
            }
            else
            {
                order--;
                if(s[i - 1] == '(')
                {
                    res += (1 << order);
                }
            }
        }
        return res;
    }
};