class Solution {
public:
    int maximum69Number (int num) {
        int n = num;
        int toAdd = 0;
        int i = 0;
        while(n > 0)
        {
            if(n % 10 == 6)
            {
                toAdd = 3 * pow(10, i);
            }
            n /= 10;
            i++;
        }
        return num + toAdd;
    }
};