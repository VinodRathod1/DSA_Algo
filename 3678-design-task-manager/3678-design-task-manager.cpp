#include <bits/stdc++.h>
using namespace std;

class TaskManager {
    struct Task {
        int priority;
        int taskId;
        int userId;
    };
    struct Compare {
        bool operator()(const Task& a, const Task& b) const {
            if (a.priority == b.priority)
                return a.taskId < b.taskId; // higher taskId first
            return a.priority < b.priority;   // higher priority first
        }
    };

    priority_queue<Task, vector<Task>, Compare> pq;
    // taskId -> {userId, priority}
    unordered_map<int, pair<int,int>> mp;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            mp[taskId] = {userId, priority};
            pq.push({priority, taskId, userId});
        }
    }

    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        auto it = mp.find(taskId);
        if (it == mp.end()) return;
        int userId = it->second.first;
        it->second.second = newPriority;
        pq.push({newPriority, taskId, userId});
    }

    void rmv(int taskId) {
        mp.erase(taskId);
    }

    int execTop() {
        while (!pq.empty()) {
            Task top = pq.top();
            auto it = mp.find(top.taskId);
            // valid only if task exists in map and priority matches current priority
            if (it != mp.end() && it->second.second == top.priority) {
                pq.pop();
                int userId = it->second.first; // use current userId from map
                mp.erase(it);
                return userId;
            }
            pq.pop(); // discard outdated entry
        }
        return -1;
    }
};
