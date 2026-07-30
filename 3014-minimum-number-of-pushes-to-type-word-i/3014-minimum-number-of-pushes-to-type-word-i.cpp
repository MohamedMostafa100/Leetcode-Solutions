class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int qtnt = n / 8;
        int rem = n % 8;
        return 8 * qtnt * (qtnt + 1) / 2 + rem * (qtnt + 1);
    }
};