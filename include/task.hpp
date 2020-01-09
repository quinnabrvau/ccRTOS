#pragma once
#include "pqNode.hpp"

class task
{
public:
    typedef const task* pTask;
    typedef pqNode<pTask> tNode;

private:
    tNode stackNode;

public:

    task() : stackNode(0,this) {};
    task(int prio) : stackNode(prio,this) {};


    tNode* get_node() {return &stackNode;}
};
