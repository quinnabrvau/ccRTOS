#pragma once
#include <cstddef>
template <typename T>
class pqNode
{
    T val;
    int priority;
public:
    pqNode *next = NULL, *prev = NULL;
    pqNode() : priority(0) {}
    pqNode(int in_priority, T in) : val(in), priority(in_priority) {}

    T operator*() {
        return val;
    }
    bool operator>(pqNode other)  {return priority <  other.priority;}
    bool operator>=(pqNode other) {return priority <= other.priority;}
    bool operator==(pqNode other) {return priority == other.priority;}
    bool operator<(pqNode other)  {return priority >  other.priority;}
    bool operator<=(pqNode other) {return priority >= other.priority;}
    bool operator!=(pqNode other) {return priority != other.priority;}

    bool operator==(int other) {return priority == other;}
    bool operator!=(int other) {return priority != other;}

    bool is(pqNode other) {return (priority == other.priority) && (val == other.val);}
};