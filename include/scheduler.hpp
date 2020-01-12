#pragma once
#include "task.hpp"
#include "prioQueue.hpp"
#include <vector>


class scheduler
{
private:
    prioQueue<pTask> readyStack;
    prioQueue<pTask> waitingStack;
    std::vector<pTask> allTasks;
    pTask running = NULL;
    bool started = false;
    
    bool removeAllTask(pTask pT) {
        for (auto it = allTasks.begin(); it != allTasks.end(); it++) {
            if (*it == pT) {
                allTasks.erase(it);
                return true;
            }
        }
        return false;
    }
    pTask runningStop() {
        pTask out = running;
        running = NULL;
        return out;
    }
    void runningStart(pTask T) {
        running = T;
    }
    void suspend(pTask pT) {
        if (pT == running) {
            runningStop();
        } else {
            readyStack.pop(pT->get_node());
        }
        if (started) run();
    }
    
    
public:
    int total() {return allTasks.size();}
    int ready() {return readyStack.size();}
    int waiting() {return waitingStack.size();}

    void add(task &T) {
        if (readyStack.push(T.get_node()))
            allTasks.push_back(&T);
        if (started) {
            run();
        }
    }
    void remove(task &T) {
        removeAllTask(&T);
        suspend(&T);
    }
    void remove() {
        remove(*running);
    }


    void start() {
        started = true;
        run();
    }
    void suspend(task &T) {
        suspend(&T);
    }
    void suspend() {
        suspend(*running);
    }
    void resume(task &T) {
        if (&T == running) {
            return;
        }
        if (readyStack.push(T.get_node()))
            run();
    }

    void delay(unsigned int ticks = 1) {
        pTask pT = runningStop();
        tNode * N = pT->get_wait_node();
        N->set_ticks(ticks);
        waitingStack.push(N);
        run();
    }
    void tick(unsigned int ticks = 1) {
        bool do_run = false;
        for (auto it = waitingStack.begin(); it != waitingStack.end(); ) {
            tNode * N = *it;
            it++;
            if (N->dec(ticks)) {
                waitingStack.pop(N);
                readyStack.push((**N)->get_node());
                do_run = true;
            }
        }
        if (do_run) {
            run();
        }
    }
    
#ifdef TESTING
public:
#else
private:
#endif
    void run() {
        tNode * p_node = readyStack.pop();
        if (p_node == NULL) {
            //do nothing;
        } else if (running == NULL) {
            runningStart( **p_node );
        } else if (*p_node > *running->get_node()) {
            readyStack.push(running->get_node());
            runningStart( **p_node );
        } else {
            readyStack.push(p_node);
        }
    }
    
    
    pTask active () {
        return running;
    }

};



