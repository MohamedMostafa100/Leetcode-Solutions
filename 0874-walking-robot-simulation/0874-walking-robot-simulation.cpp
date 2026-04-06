class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int res = 0;
        int x = 0;
        int y = 0;
        int curDir = 0;
        unordered_set<int> obs;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < obstacles.size(); i++) {
            obs.insert(obstacles[i][0] * 60013 + obstacles[i][1]);
        }
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -1) {
                curDir++;
                curDir = ((curDir % 4) + 4) % 4;
                continue;
            } else if (commands[i] == -2) {
                curDir--;
                curDir = ((curDir % 4) + 4) % 4;
                cout << curDir << endl;
                continue;
            }
            for(int j = 0; j < commands[i]; j++)
            {
                if(obs.count((x + dirs[curDir].first) * 60013 + (y + dirs[curDir].second)))
                {
                    break;
                }
                x += dirs[curDir].first;
                y += dirs[curDir].second;
                res = max(res, x * x + y * y);
            }
        }
        return res;
    }
};