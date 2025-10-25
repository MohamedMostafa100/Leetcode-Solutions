class Solution {
public:
    int totalMoney(int n) {
        int div = n / 7;
        int rem = n % 7;
        int rep = max(0, div - 1);
        return (28 * div) + 7 * (rep * (rep + 1) / 2) + (rem * (2 * div + 1 + rem) / 2);
    }
};