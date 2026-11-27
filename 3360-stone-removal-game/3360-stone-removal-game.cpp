class Solution {
public:
    bool canAliceWin(int n) {
        int tot = (55 - n) * 2;
        int x = ceil((-1 + sqrt(1 + 4 * tot)) / 2);
        cout << x;
        return x % 2 == 1;
    }
};