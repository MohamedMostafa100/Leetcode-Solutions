class Solution {
public:
    int countCollisions(string directions) {
        int res = 0;
        stack<char> stk;
        for (int i = 0; i < directions.size(); i++) {
            if (directions[i] == 'R') {
                stk.push('R');
            } else if (directions[i] == 'S') {
                while (!stk.empty() && stk.top() == 'R') {
                    res += 1;
                    stk.pop();
                }
                stk.push('S');
            } else {
                if (!stk.empty()) {
                    if (stk.top() == 'R') {
                        res += 2;
                        stk.pop();
                        while (!stk.empty() && stk.top() == 'R') {
                            res += 1;
                            stk.pop();
                        }
                        stk.push('S');
                    } else if (stk.top() == 'S') {
                        res += 1;
                    }
                }
            }
        }
        return res;
    }
};