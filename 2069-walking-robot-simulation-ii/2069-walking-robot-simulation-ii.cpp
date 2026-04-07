class Robot {
    int width, height, perimeter;
    int x, y, curDir;
    vector<pair<int, int>> dirs;
    vector<string> cardDirs;
public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        perimeter = 2 * width + 2 * height - 4;
        x = 0;
        y = 0;
        curDir = 0;
        dirs = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        cardDirs = {"East", "South", "West", "North"};
    }
    
    void step(int num) {
        num %= perimeter;
        if (num == 0) {
            if (x == 0 && y == 0)
            {
                curDir = 1;
            } 
            return;
        }
        curDir = (curDir + 1) % 4;
        while (num > 0) {
            curDir = (curDir - 1 + 4) % 4;
            if (dirs[curDir].second == 0) {
                int limit = width;
                if (dirs[curDir].first < 0) limit = -1;
                int dis = min(num, abs(limit - x));
                int distToWall = (limit > 0) ? (limit - 1 - x) : (x - (limit + 1)); 
                int move = min(num, abs(limit - x)); 
                move = min(num, abs(limit - x) - 1); 
                x += move * dirs[curDir].first;
                num -= move;
            } else {
                int limit = height;
                if (dirs[curDir].second < 0) limit = -1;
                int move = min(num, abs(limit - y) - 1);
                y += move * dirs[curDir].second;
                num -= move;
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return cardDirs[curDir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */