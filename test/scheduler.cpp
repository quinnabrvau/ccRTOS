#include "scheduler.hpp"
#include "TestHarness.h"

TEST_GROUP(schedulerCreate)
{
    void setup() { }
    void teardown() { }
};

TEST(schedulerCreate, initEmptyPrioQueue) {
    scheduler S;
    CHECK_EQUAL(0, S.total());
}
TEST(schedulerCreate, addTaskSize1) {
    scheduler S;
    task t;
    S.add(t);
    CHECK_EQUAL(1, S.total());
}
TEST(schedulerCreate, addTaskSize30) {
    scheduler S;
    task T[30];
    for (int i = 0; i < 30; i++) {
        S.add(T[i]);
        CHECK_EQUAL(i+1, S.total());
    }
}

TEST_GROUP(schedulerRun)
{
    void setup() { }
    void teardown() { }
};

TEST(schedulerRun, start1Task) {
    scheduler S;
    task t;
    S.add(t);
    S.start();
    CHECK_EQUAL(1, S.ready());
}
TEST(schedulerRun, start2Task) {
    scheduler S;
    task t[2];
    S.add(t[0]); S.add(t[1]);
    S.start();
    CHECK_EQUAL(2, S.ready());
}


