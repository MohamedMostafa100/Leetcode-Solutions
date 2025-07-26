class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = 1;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            int l = i;
            int r = i + 1;
            while (l >= 0 && r < s.length()) {
                if (s[l] == s[r]) {
                    if (r - l + 1 > maxLength) {
                        maxLength = r - l + 1;
                        start = l;
                    }
                    l--;
                    r++;
                } else {
                    break;
                }
            }

            l = i - 1;
            r = i + 1;
            while (l >= 0 && r < s.length()) {
                if (s[l] == s[r]) {
                    if (r - l + 1 > maxLength) {
                        maxLength = r - l + 1;
                        start = l;
                    }
                    l--;
                    r++;
                } else {
                    break;
                }
            }
        }
        return s.substr(start, maxLength);
    }
};