#pragma once
#include "task.hpp"
#include "prioQueue.hpp"


class scheduler
{
public:
    typedef task::tNode tNode;
private:
    prioQueue<task::pTask> readyStack;
    // prioQueue<task::pTask> waitingStack;
    prioQueue<task::pTask> allTasks;
public:
    int total() {return allTasks.size() + readyStack.size();}
    int ready() {return readyStack.size();}

    void add(task &T) {
        readyStack.push(T.get_node());
    }
    void start() {

    }

};



