#include "pqNode.hpp"

#define CLEAR(n) n->next=n->prev=NULL
#define NEXT(n) n=n->next
#define VERIFY_DIFFERENT(a,b) if ((a)==(b)) return false

template <typename T>
class prioQueue
{
public:
    typedef pqNode<T> node;

private:
    typedef pqNode<T> * itterator;
    itterator head;
    int length;

    void pair(itterator first, itterator second) {
        first->next = second;
        second->prev = first;
    }
    void make_head(itterator N) {
        CLEAR(N);
        if (head != NULL)
            pair(N, head);
        head = N;
    }

public:
    prioQueue() {
        head = NULL;
        length = 0;
    }

    int size() {return this->length;}

    bool push(node * N) {
        VERIFY_DIFFERENT(N, NULL);
        if (head == NULL) {
            make_head(N);
            length++;
            return true;
        }
        VERIFY_DIFFERENT(N, head);
        itterator itter = head;
        while(itter->next != NULL && *itter >= *N) {
            VERIFY_DIFFERENT(N, itter);
            NEXT(itter);
        }

        CLEAR(N);
        if (itter == head && *itter < *N) {
            make_head(N);
        } else if (itter->next != NULL) {
            pair(N, itter->next);
        }
        pair(itter, N);
        length++;
        return true;
    }

    node * pop() {
        if (head == NULL) return NULL;
        node * out = head;
        head = head->next;
        length--;
        return out;
    }
    
};