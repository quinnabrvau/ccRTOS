#pragma once
#include "pqNode.hpp"

class task
{
public:
    typedef task* pTask;
    typedef pqNode<pTask> tNode;

private:
    tNode waitNode = tNode(0, this, true);
    tNode stackNode;

public:

    task() : stackNode(0, this) {};
    task(int priority) : stackNode(priority,this) {};


    tNode* get_node() {return &stackNode;}
    tNode* get_wait_node() {return &waitNode;}
    task* get_p() {return this;}
};

typedef task::tNode tNode;
typedef task::pTask pTask;
