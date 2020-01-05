#include <cstddef>
template <typename T>
class pqNode
{
public:
    pqNode *next, *prev;
    T val;
    pqNode() {
        next = NULL;
        prev = NULL;
    }
    pqNode(T in) {
        next = NULL;
        prev = NULL;
        val = in;
    }
    
    T operator*() {
        return val;
    }
};