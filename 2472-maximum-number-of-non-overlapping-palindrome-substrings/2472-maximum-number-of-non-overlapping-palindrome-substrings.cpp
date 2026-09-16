class Solution {
public:
    int maxPalindromes(string s, int k) {
        int res = 0;
        int start = 0;
        for (int r = k - 1; r < s.length(); r++) {
            if ((r - k + 1 >= start && check(s, r - k + 1, r)) ||
                (r - k >= start && check(s, r - k, r))) {
                res++;
                start = r + 1;
            }
        }
        return res;
    }

private:
    bool check(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};