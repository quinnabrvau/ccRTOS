#pragma once
#include "task.hpp"
#include "prioQueue.hpp"
#include <vector>


class scheduler
{
private:
    prioQueue<pTask> readyStack;
    // prioQueue<pTask> waitingStack;
    std::vector<pTask> allTasks;
    pTask running = NULL;
    bool started = false;
public:
    int total() {return allTasks.size();}
    int ready() {return readyStack.size();}
    int waiting() {return 0;}

    void add(task &T) {
        if (readyStack.push(T.get_node()))
            allTasks.push_back(&T);
        if (started) {
            run();
        }
    }
    void remove() {

    }


    void start() {
        started = true;
        run();
    }
    pTask active () {
        return running;
    }

    void suspend() {
        running = NULL;
        run();
    }
    void suspend(task &T) {
        if (&T == running) {
            running = NULL;
            run();
        } else {
            readyStack.pop(T.get_node());
        }

    }
    void resume(task &T) {
        if (readyStack.push(T.get_node()))
            run();
    }


    void run() {
        tNode * p_node = readyStack.pop();
        if (p_node == NULL) {
            //do nothing;
        } else if (running == NULL) {
            running = **p_node;
        } else if (*p_node > *running->get_node()) {
            readyStack.push(running->get_node());
            running = **p_node;
        } else {
            readyStack.push(p_node);
        }
    }

};



