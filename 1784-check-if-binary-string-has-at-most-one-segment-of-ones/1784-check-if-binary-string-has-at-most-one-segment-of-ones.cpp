class Solution {
public:
    bool checkOnesSegment(string s) {
        bool finished = false;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '0' && !finished)
            {
                finished = true;
            }
            else if(s[i] == '1' && finished)
            {
                return false;
            }
        }
        return true;
    }
};