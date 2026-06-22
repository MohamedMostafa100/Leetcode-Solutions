class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<string> stk;
        string num = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                num += s[i];
            }
            else if(s[i] == '[')
            {
                stk.push(res);
                stk.push(num);
                num = "";
                res = "";
            }
            else if(s[i] == ']')
            {
                string toRepeat = res;
                int repeat = stoi(stk.top()) - 1;
                stk.pop();
                for(int j = 0; j < repeat; j++)
                {
                    res += toRepeat;
                }
                res = stk.top() + res;
                stk.pop(); 
            }
            else
            {
                res += s[i];
            }
        }
        return res;
    }
};