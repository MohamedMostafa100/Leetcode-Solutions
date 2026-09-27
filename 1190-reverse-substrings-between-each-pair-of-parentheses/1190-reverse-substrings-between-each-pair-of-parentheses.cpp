class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                vector<char> stk;
                stk.push_back('(');
                i++;
                while (true) {
                    if (s[i] == ')') {
                        string cur = "";
                        while (stk.back() != '(') {
                            cur += stk.back();
                            stk.pop_back();
                        }
                        stk.pop_back();
                        for (int j = 0; j < cur.length(); j++) {
                            stk.push_back(cur[j]);
                        }
                        if(stk.empty() || stk[0] != '(')
                        {
                            break;
                        }
                    } else {
                        stk.push_back(s[i]);
                    }
                    i++;
                }
                for (int j = 0; j < stk.size(); j++) {
                    res += stk[j];
                }
            } else {
                res += s[i];
            }
        }
        return res;
    }
};