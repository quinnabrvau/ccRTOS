#pragma once
#include <cstddef>
template <typename T>
class pqNode
{
    T val;
    union { // priority is used in stackQueue, ticks in waitingQueue
        unsigned int priority;
        unsigned int ticks;
    };
    
    bool wait = false;
public:
    pqNode *next = NULL, *prev = NULL;
    pqNode() : priority(0) {}
    pqNode(int in_priority, T in) : val(in), priority(in_priority) {}
    pqNode(int in_priority, T in, bool in_wait) : val(in), priority(in_priority), wait(in_wait) {}
    
    T operator*() {
        return val;
    }
    
    unsigned int get_priority() const { return priority;}
    
    bool operator>(pqNode other)  {return priority <  other.priority;}
    bool operator>=(pqNode other) {return priority <= other.priority;}
    bool operator==(pqNode other) {return priority == other.priority;}
    bool operator<(pqNode other)  {return priority >  other.priority;}
    bool operator<=(pqNode other) {return priority >= other.priority;}
    bool operator!=(pqNode other) {return priority != other.priority;}

    bool operator==(int other) {return priority == other;}
    bool operator!=(int other) {return priority != other;}

    bool is(pqNode other) {return (priority == other.priority) && (val == other.val);}
    
    
// USED in waiting stack
    bool dec(unsigned int in_ticks = 1) {
        if (wait) {
            if (ticks <= in_ticks) {
                ticks = 0;
                return true;
            } else  {
                ticks -= in_ticks;
                return false;
            }
        } else {
            ///@todo raise exception
        }
        return false;
    }
    
    bool set_ticks(unsigned int in_ticks) {
        if (wait) {
            ticks = in_ticks;
            return true;
        } else {
            ///@todo raise exception
        }
        return false;
    }
};
