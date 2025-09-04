class Solution {
public:
    int findClosest(int x, int y, int z) {
        unsigned char dist1 = abs(z - x);
        unsigned char dist2 = abs(z - y);
        return dist1 < dist2 ? 1 : dist1 > dist2 ? 2 : 0;
    }
};