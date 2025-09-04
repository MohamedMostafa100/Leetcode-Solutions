class Solution {
public:
    int findClosest(int x, int y, int z) {
        return abs(z - x) < abs(z - y) ? 1 : abs(z - x) > abs(z - y) ? 2 : 0;
    }
};