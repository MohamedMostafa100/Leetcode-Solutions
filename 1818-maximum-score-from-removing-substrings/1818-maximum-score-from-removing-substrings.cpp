class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string newStr = "";
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (newStr.empty() || s[i] > 'b') {
                newStr += s[i];
            } else {
                if (x >= y) {
                    if (s[i] == 'b' && newStr[newStr.length() - 1] == 'a') {
                        res += x;
                        newStr.pop_back();
                    } else {
                        newStr += s[i];
                    }
                } else {
                    if (s[i] == 'a' && newStr[newStr.length() - 1] == 'b') {
                        res += y;
                        newStr.pop_back();
                    } else {
                        newStr += s[i];
                    }
                }
            }
        }
        string newNewStr = "";
        for (int i = 0; i < newStr.length(); i++) {
            if (newNewStr.empty() || newStr[i] > 'b') {
                newNewStr += newStr[i];
            } else {
                if (newStr[i] == 'b' &&
                    newNewStr[newNewStr.length() - 1] == 'a') {
                    res += x;
                    newNewStr.pop_back();
                } else if (newStr[i] == 'a' &&
                           newNewStr[newNewStr.length() - 1] == 'b') {
                    res += y;
                    newNewStr.pop_back();
                } else {
                    newNewStr += newStr[i];
                }
            }
        }
        return res;
    }
};