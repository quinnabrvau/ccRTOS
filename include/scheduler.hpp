#pragma once
#include "task.hpp"
#include "prioQueue.hpp"

class scheduler
{
    // prioQueue<task::pTask> readyStack;
    // prioQueue<task::pTask> waitingStack;
    prioQueue<task::pTask> allTasks;
public:
    int total() {return allTasks.size();}

    void add(task &T) {
        allTasks.push(T.get_node());
    }

};



