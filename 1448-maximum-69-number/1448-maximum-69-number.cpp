class Solution {
public:
    int maximum69Number (int num) {
        int n = num;
        int toAdd = 0;
        int i = 1;
        while(n > 0)
        {
            if(n % 10 == 6)
            {
                toAdd = 3 * i;
            }
            n /= 10;
            i *= 10;
        }
        return num + toAdd;
    }
};