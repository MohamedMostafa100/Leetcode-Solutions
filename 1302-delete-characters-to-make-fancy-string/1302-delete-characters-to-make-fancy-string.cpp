class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        char lastChar = s[0];
        res += lastChar;
        int vioCount = 1;

        for(int i = 1; i < s.length(); i++){
            if(lastChar == s[i])
            {
                vioCount++;
                if(vioCount >= 3)
                {
                    continue;
                }
            }
            else
            {
                lastChar = s[i];
                vioCount = 1;
            }
            res += s[i];
        }
        return res;
    }
};