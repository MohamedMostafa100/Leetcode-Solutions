class Solution {
public:
    bool checkString(string s) {
        bool sFlag = false;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a')
            {
                if(sFlag)
                {
                    return false;
                }
            }
            else
            {
                sFlag = true;
            }
        }
        return true;
    }
};