class Robot:

    def __init__(self, width: int, height: int):
        self.width = width
        self.height = height 
        self.perimeter = 2 * self.width + 2 * self.height - 4
        self.x = 0
        self.y = 0
        self.curDir = 0
        self.dirs = [(1, 0), (0, -1), (-1, 0), (0, 1)]
        self.cardDirs = ["East", "South", "West", "North"]

    def step(self, num: int) -> None:
        num %= self.perimeter
        if num == 0:
            if self.x == 0 and self.y == 0:
                self.curDir = 1
            return
        self.curDir = (self.curDir + 1) % 4 
        while num > 0:
            self.curDir = (self.curDir - 1) % 4 
            if self.dirs[self.curDir][1] == 0:
                limit = self.width
                if self.dirs[self.curDir][0] < 0:
                    limit = -1
                disX = min(num, abs(limit - self.x) - 1)
                self.x += disX * self.dirs[self.curDir][0]
                num -= disX
            else:
                limit = self.height
                if self.dirs[self.curDir][1] < 0:
                    limit = -1
                disY = min(num, abs(limit - self.y) - 1)
                self.y += disY * self.dirs[self.curDir][1]
                num -= disY

    def getPos(self) -> List[int]:
        return [self.x, self.y]

    def getDir(self) -> str:
        return self.cardDirs[self.curDir]


# Your Robot object will be instantiated and called as such:
# obj = Robot(width, height)
# obj.step(num)
# param_2 = obj.getPos()
# param_3 = obj.getDir()