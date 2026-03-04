class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        validStrings(res, "", n, n, n, 0);
        return res;
    }

private:
    void validStrings(vector<string>& strs, string s, int opened, int closed, int maximum, int balance)
    {
        if(opened == 0 && closed == 0)
        {
            strs.push_back(s);
            return;
        }

        if(balance != maximum && opened > 0)
        {
            validStrings(strs, s + '(', opened - 1, closed, maximum, balance + 1);
        }

        if(balance != 0 && closed > 0)
        {
            validStrings(strs, s + ')', opened, closed - 1, maximum, balance - 1);
        }
    }
};
