class Solution {
public:
    int maxOperations(string s) {
        int res = 0;
        int onesCount = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '1')
            {
                onesCount++;
            } 
            else
            {
                while(i + 1 < s.length() && s[i + 1] != '1')
                {
                    i++;
                }
                res += onesCount;
            }
        }
        return res;
    }
};