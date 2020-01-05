#include "pqNode.hpp"

#define CLEAR(n) n->next=n->prev=NULL
#define NEXT(n) n=n->next


template <typename T>
class prioQueue
{
public:
    typedef pqNode<T> node;

private:
    typedef pqNode<T> * itterator;
    itterator head;
    int length;

    void assign(itterator N, itterator at) {
        CLEAR(N);
        at = N;
        length++;
    }

public:
    prioQueue() {
        // head = NULL;
        length = 0;
    }

    int size() {return this->length;}

    bool push(node * N) {
        if (head == NULL) {
            assign(N, head);
            return true;
        }
        if (N == head) return false; // already in list

        itterator itter = head;
        while(itter->next != NULL) {
            if (N == itter) return false; // already in list
            NEXT(itter);
        }
        assign(N, itter->next);
        return true;
    }

    node * pop() {
        node * out = head;
        head = head->next;
        return out;
    }
    
};