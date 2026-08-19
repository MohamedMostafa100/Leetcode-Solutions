class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int res = 2 * n;
        unordered_map<int, int> rows;
        for (int i = 0; i < reservedSeats.size(); i++) {
            int r = reservedSeats[i][0];
            int c = reservedSeats[i][1];
            if(!rows.count(r))
            {
                rows[r] = 0;
            }
            if (c == 2 || c == 3) {
                rows[r] |= 4;
            } else if (c == 4 || c == 5) {
                rows[r] |= 4;
                rows[r] |= 2;
            } else if (c == 6 || c == 7) {
                rows[r] |= 2;
                rows[r] |= 1;
            } else if (c == 8 || c == 9) {
                rows[r] |= 1;
            }
        }
        for (auto& [r, off] : rows) {
            if (off == 7) {
                res -= 2;
            } else if (off >= 1) {
                res--;
            }
        }
        return res;
    }
};