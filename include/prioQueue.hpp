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
        if (head == NULL) {
            make_head(N);
            length++;
            return true;
        }
        if (N == head) return false; // already in list

        itterator itter = head;
        while(itter->next != NULL && *itter >= *N) {
            if (N == itter) return false; // already in list
            NEXT(itter);
        }
        if (itter == head && *itter < *N) {
            make_head(N);
        } else if (itter->next == NULL) {
            CLEAR(N);
        } else {
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