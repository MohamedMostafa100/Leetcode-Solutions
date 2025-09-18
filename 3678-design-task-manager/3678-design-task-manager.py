class TaskManager:

    def __init__(self, tasks: List[List[int]]):
        self.taskMap = {}
        self.taskQueue = SortedSet()
        for userId, taskId, priority in tasks:
            self.taskMap[taskId] = (userId, priority)
            self.taskQueue.add((priority, taskId))

    def add(self, userId: int, taskId: int, priority: int) -> None:
        self.taskMap[taskId] = (userId, priority)
        self.taskQueue.add((priority, taskId))

    def edit(self, taskId: int, newPriority: int) -> None:
        self.taskQueue.remove((self.taskMap[taskId][1], taskId))
        self.taskQueue.add((newPriority, taskId))
        self.taskMap[taskId] = (self.taskMap[taskId][0], newPriority)

    def rmv(self, taskId: int) -> None:
        self.taskQueue.remove((self.taskMap[taskId][1], taskId))
        self.taskMap.pop(taskId)

    def execTop(self) -> int:
        if len(self.taskQueue) > 0:
            taskInfo = self.taskQueue[-1]
            userId = self.taskMap[taskInfo[1]][0]
            self.taskQueue.pop()
            self.taskMap.pop(taskInfo[1])
            return userId
        return -1


# Your TaskManager object will be instantiated and called as such:
# obj = TaskManager(tasks)
# obj.add(userId,taskId,priority)
# obj.edit(taskId,newPriority)
# obj.rmv(taskId)
# param_4 = obj.execTop()