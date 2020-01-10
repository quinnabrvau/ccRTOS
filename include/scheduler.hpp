#pragma once
#include "task.hpp"
#include "prioQueue.hpp"


class scheduler
{
public:
    typedef task::tNode tNode;
    typedef task::pTask pTask;
private:
    prioQueue<task::pTask> readyStack;
    // prioQueue<task::pTask> waitingStack;
    prioQueue<task::pTask> allTasks;
    pTask running = NULL;
    bool started = false;
public:
    int total() {return allTasks.size() + readyStack.size();}
    int ready() {return readyStack.size();}
    int waiting() {return 0;}

    void add(task &T) {
        readyStack.push(T.get_node());
        if (started) {
            run();
        }
    }
    void start() {
        started = true;
    }
    pTask active () {
        return running;
    }

    void suspend(task &T) {
        readyStack.pop(T.get_node());
    }
    void run() {
        tNode * p_node = readyStack.pop();
        if (running == NULL) {
            running = **p_node;
        } else if (*p_node > *running->get_node()) {
            readyStack.push(running->get_node());
        } else {
            readyStack.push(p_node);
        }
    }

};



