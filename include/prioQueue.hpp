#include "pqNode.hpp"

template <typename T>
class prioQueue
{
    // pqNode<T> *head;
    int length;

public:

    prioQueue() {
        // head = NULL;
        length = 0;
    }

    int size() {return this->length;}
    
};