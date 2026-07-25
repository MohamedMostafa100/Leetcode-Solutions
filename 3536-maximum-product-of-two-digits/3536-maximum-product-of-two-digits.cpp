class Solution {
public:
    int maxProduct(int n) {
        char res = 0;
        char mx = 0;
        while(n > 0)
        {
            char rem = n % 10;
            res = max(res, (char)(mx * rem));
            mx = max(mx, rem);
            n /= 10;
        }
        return res;
    }
};