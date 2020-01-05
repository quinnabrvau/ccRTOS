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
};