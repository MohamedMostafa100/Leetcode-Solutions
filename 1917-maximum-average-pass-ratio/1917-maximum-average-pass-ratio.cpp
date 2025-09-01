
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        auto compare = [&](int a, int b) {
            double q1 =
                (((double)classes[a][0] + 1) / ((double)classes[a][1] + 1)) -
                ((double)classes[a][0] / classes[a][1]);
            double q2 =
                (((double)classes[b][0] + 1) / ((double)classes[b][1] + 1)) -
                ((double)classes[b][0] / classes[b][1]);
            return q1 < q2;
        };

        priority_queue<int, vector<int>, decltype(compare)> pq(compare);

        for (int i = 0; i < n; i++) {
            pq.push(i);
        }

        for (int i = 0; i < extraStudents; i++) {
            int topIndex = pq.top();
            pq.pop();
            classes[topIndex][0]++;
            classes[topIndex][1]++;
            pq.push(topIndex);
        }

        double res = 0;
        for (int i = 0; i < n; i++) {
            res += ((double)classes[i][0] / classes[i][1] / n);
        }
        return res;
    }
};