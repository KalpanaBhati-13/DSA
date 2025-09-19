
#include <bits/stdc++.h>
using namespace std;

class TaskManager {
public:
    typedef pair<int, int> P; // priority, taskId
    priority_queue<P> maxHeap; 
    unordered_map<int, int> taskPriorityMap; // taskId -> priority
    unordered_map<int, int> taskOwnerMap;    // taskId -> userId

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        maxHeap.push({priority, taskId});
        taskPriorityMap[taskId] = priority;
        taskOwnerMap[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        maxHeap.push({newPriority, taskId});
        taskPriorityMap[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        // Lazy delete → mark as invalid
        taskPriorityMap[taskId] = -1;
    }
    
    int execTop() {
        while (!maxHeap.empty()) {
            auto [prior, taskId] = maxHeap.top();
            maxHeap.pop();

            // valid task check
            if (prior == taskPriorityMap[taskId]) {
                taskPriorityMap[taskId] = -1; // mark executed
                return taskOwnerMap[taskId];  // return userId
            }
        }
        return -1; // no valid tasks
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