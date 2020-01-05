#include <cstddef>
template <typename T>
class node
{
public:
    node *next, *prev;
    T val;
    node() {
        next = NULL;
        prev = NULL;
    }
    node(T in) {
        next = NULL;
        prev = NULL;
        val = in;
    }
    
    T operator*() {
        return val;
    }
};