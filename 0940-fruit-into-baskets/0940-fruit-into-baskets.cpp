class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        int l = 0;
        int type1 = -1;
        int type2 = -1;
        int jumpNum = -1;
        int jumpIdx = -1;
        for (int r = 0; r < fruits.size(); r++) {
            if (type1 == -1) {
                type1 = fruits[r];
                jumpNum = type1;
                jumpIdx = r;
            } else if (type2 == -1 && fruits[r] != type1) {
                type2 = fruits[r];
            } else if (fruits[r] != type1 && fruits[r] != type2) {
                type2 = fruits[r];
                l = jumpIdx;
                type1 = fruits[l];
            }
            if (fruits[r] != jumpNum) {
                jumpNum = fruits[r];
                jumpIdx = r;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};