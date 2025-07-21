class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        res += s[0];
        if(s.length() > 1)
        {
            res += s[1];
        }
        for(int i = 2; i < s.length(); i++){
            if(s[i] == s[i - 1] && s[i - 1] == s[i - 2])
            {
                continue;
            }
            res += s[i];
        }
        return res;
    }
};