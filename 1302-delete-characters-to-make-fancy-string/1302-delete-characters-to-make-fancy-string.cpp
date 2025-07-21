class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        res += s[0];
        int vioCount = 0;
        for(int i = 1; i < s.length(); i++){
            if(s[i] == s[i - 1])
            {
                vioCount++;
                if(vioCount >= 2)
                {
                    continue;
                }
            }
            else
            {
                vioCount = 0;
            }
            res += s[i];
        }
        return res;
    }
};