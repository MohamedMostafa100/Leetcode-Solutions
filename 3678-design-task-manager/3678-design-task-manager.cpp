class TaskManager {
private:
    unordered_map<int, pair<int, int>> taskMap;
    set<pair<int, int>> taskQueue;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0; i < tasks.size(); i++)
        {
            taskMap[tasks[i][1]] = {tasks[i][0], tasks[i][2]};
            taskQueue.insert({tasks[i][2], tasks[i][1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        taskQueue.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        taskQueue.erase({taskMap[taskId].second, taskId});
        taskQueue.insert({newPriority, taskId});
        taskMap[taskId].second = newPriority;
    }
    
    void rmv(int taskId) {
        taskQueue.erase({taskMap[taskId].second, taskId});
        taskMap.erase(taskId);
    }
    
    int execTop() {
        if(!taskQueue.empty())
        {
            pair<int, int> taskInfo = *prev(taskQueue.end()); 
            int userId = taskMap[taskInfo.second].first;
            taskQueue.erase(prev(taskQueue.end()));
            taskMap.erase(taskInfo.second);
            return userId;
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */