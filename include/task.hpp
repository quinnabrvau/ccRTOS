#pragma once
#include "pqNode.hpp"

class task
{
public:
    typedef task* pTask;
    typedef pqNode<pTask> tNode;

private:
    tNode stackNode;
    const int prio;

public:

    task() : prio(0), stackNode(0,this) {};
    task(int priority) : prio(priority), stackNode(priority,this) {};


    tNode* get_node() {return &stackNode;}
    task* get_p() {return this;}
};

typedef task::tNode tNode;
typedef task::pTask pTask;